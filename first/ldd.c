#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dark_Programmer");
MODULE_DESCRIPTION("My first kernel loadable driver");

static int cons(void){
    printk("Hello Driver !!!");
    return 0;
}

static void dest(void){
    printk("GoodBye Driver !!!");
}

module_init(cons);
module_exit(dest);