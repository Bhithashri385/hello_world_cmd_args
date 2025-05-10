#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hithasrhi");

char my_string_param[64] = "";
module_param_string(my_string_param, my_string_param, sizeof(my_string_param), 0); 

static int __init hello_init(void) {
    printk(KERN_INFO "Hello, world!\n");
    printk(KERN_INFO "Hello world! %s\n",my_string_param);

    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, world!\n");
}

module_init(hello_init);
module_exit(hello_exit);
