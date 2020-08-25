/*
 * Filename: seqfile.h
 * Version: 1.0
 * Description: Declare seqfile create/destory functions, 
 *              used for reading device info from /proc file
 * Author: Huang Ye
 * History: 
*/

/************************************************************
 * function: 
 *      int create_seq_file(struct proc_dir_entry *entry, 
 *                          umode_t mode, 
 *                          struct proc_dir_entry *parent)
 * description: 
 *      warp func of proc_create(), create a single_open seqfile 
 *      only with show() method.
 * return: 
 *      success: 1
 *      error: -1
 **********************************************************/
int create_seq_file(void * proc_dir_entry, umode_t mode, void * proc_dir_entry_parent);

/************************************************************
 * function: 
 *      void remove_seq_file(struct proc_dir_entry *entry)
 * description: 
 *      warp func of proc_remove();
 * return: 
 *      success: 1
 *      error: -1
 **********************************************************/
void remove_seq_file(void * proc_dir_entry);