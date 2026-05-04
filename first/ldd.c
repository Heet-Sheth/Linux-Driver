#include<linux/init.h>
#include<linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dark_Programmer");
MODULE_DESCRIPTION("My first kernel loadable driver");

ssize_t writeFunction(struct file *currentFile, const char __user *currentUser, size_t currentSize, loff_t *currentlOff){
    printk("Driver write hit");
    return 0;
}

ssize_t readFunction(struct file *currentFile, char __user *currentUser, size_t currentSize, loff_t *currentlOff){
    printk("Driver read hit");
    return 0;
}

struct proc_dir_entry *proc_dir_entry_variable;
struct proc_ops operations = {
    .proc_read = readFunction,
    .proc_write = writeFunction
};

static int cons(void){
    printk("INIT, enter");
    proc_dir_entry_variable = proc_create("Driver_1", 0, NULL, &operations);
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