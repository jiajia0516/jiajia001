#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/input.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <linux/slab.h>
#include <linux/fb.h>
#include <linux/mm.h>
#include <asm/uaccess.h> 
#include <asm/device.h> //下面这三个头文件是由于动态创建需要加的
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/input.h>
#include <linux/wait.h>
/* 定义幻数 */
#define MEMDEV_IOC_MAGIC  'k'
/* 定义命令 */
#define MEMDEV_IOCPRINT   _IO(MEMDEV_IOC_MAGIC, 1)
#define MEMDEV_IOCGETDATA _IOR(MEMDEV_IOC_MAGIC, 2, int)
#define MEMDEV_IOCSETDATA _IOW(MEMDEV_IOC_MAGIC, 3, int)
#define MEMDEV_IOC_MAXNR 3

#define DEVICENAME "ubuntu_event"

struct cdev *cdev_t;
dev_t dev=0;
static struct class *cdev_class; 


DECLARE_WAIT_QUEUE_HEAD(name); 
static DECLARE_WAIT_QUEUE_HEAD(wq);
struct input_event inputData;
int have_data = 0; /*表明设备有足够数据可供读*/

static int ubuntu_event_open(struct inode *inodep, struct file *filep)
{
    printk("read success!\n");
	memset(&inputData, 0, sizeof(inputData));
    return 0;
}

static int ubuntu_event_release(struct inode *inodep, struct file *filep)
{
    return 0;
}
static ssize_t ubuntu_event_read (struct file *filep, char __user *buf, size_t count, loff_t *offset)
{
    wait_event_interruptible(wq, have_data!=0);
    if(copy_to_user(buf,&inputData,count))
    {
        return -EFAULT;
    }    
    have_data -=1;
    return count;
}

static ssize_t ubuntu_event_write (struct file *filep, const char __user *buf,size_t count, loff_t *offse)
{

    if(copy_from_user(&inputData,buf,count))
    {
        return -EFAULT;
    }
    printk("write %s\n",inputData.value);
    have_data +=1;
    wake_up_interruptible(&wq);
    return count;
}


static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = ubuntu_event_open,
    .release = ubuntu_event_release,
    .read = ubuntu_event_read,
    .write = ubuntu_event_write,
};

static int __init ubuntu_event_init(void)
{
    int ret = alloc_chrdev_region(&dev, 0, 1, DEVICENAME);
    if(ret)
    {
    	printk("mydrv register fail");
		unregister_chrdev_region(dev,1);
	return ret;
    }else
    {
    	cdev_t =cdev_alloc();
    	cdev_t->owner=THIS_MODULE;
    	cdev_init(cdev_t, &fops);
    	ret = cdev_add(cdev_t, dev, 1);
		if(ret)
		{
			printk("cdev_add fail\n");
			unregister_chrdev_region(dev,1);
			return ret;
		}
		//动态创建设备节点
		cdev_class = class_create(THIS_MODULE,DEVICENAME);
		if(IS_ERR(cdev_class))
		{ 
			printk("ERR:cannot create a cdev_class\n");
			unregister_chrdev_region(dev,1);
			return -1;
		}
		device_create(cdev_class,NULL, dev, 0, DEVICENAME);
	}
    return 0;
}

static void __exit ubuntu_event_cleanup(void)
{
    cdev_del(cdev_t);
    device_destroy(cdev_class, dev);
	class_destroy(cdev_class);
	unregister_chrdev_region(dev,1);
}

module_init(ubuntu_event_init);
module_exit(ubuntu_event_cleanup);
MODULE_LICENSE("GPL");

