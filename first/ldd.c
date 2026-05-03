#include<linux/init.h>
#include<linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dark_Programmer");
MODULE_DESCRIPTION("My first kernel loadable driver");

struct proc_dir_entry *proc_dir_entry_variable;

static int cons(void){
    printk("INIT, enter");
    proc_dir_entry_variable = proc_create("Driver_1", 0, NULL, NULL);
    printk("INIT, exit");
    return 0;
}

static void dest(void){
    printk("EXIT, enter");
    proc_remove(proc_dir_entry_variable);
    printk("EXIT, exit");
}

module_init(cons);
module_exit(dest);