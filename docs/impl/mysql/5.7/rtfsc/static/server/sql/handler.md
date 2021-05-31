# handler


`struct handlerton`:

``` c++
struct handlerton {
  SHOW_COMP_OPTION state;
  enum legacy_db_type db_type;
  uint slot;
  uint savepoint_offset;
  uint32 flags;
  uint32 license;
  void *data;

  int  (*close_connection)(handlerton *hton, THD *thd);
  void (*kill_connection)(handlerton *hton, THD *thd);
  int  (*savepoint_set)(handlerton *hton, THD *thd, void *sv);
  int  (*savepoint_rollback)(handlerton *hton, THD *thd, void *sv);
  bool (*savepoint_rollback_can_release_mdl)(handlerton *hton, THD *thd);
  int  (*savepoint_release)(handlerton *hton, THD *thd, void *sv);
  int  (*commit)(handlerton *hton, THD *thd, bool all);
  int  (*rollback)(handlerton *hton, THD *thd, bool all);
  int  (*prepare)(handlerton *hton, THD *thd, bool all);
  int  (*recover)(handlerton *hton, XID *xid_list, uint len);
  int  (*commit_by_xid)(handlerton *hton, XID *xid);
  int  (*rollback_by_xid)(handlerton *hton, XID *xid);
  handler *(*create)(handlerton *hton, TABLE_SHARE *table, MEM_ROOT *mem_root);
  void (*drop_database)(handlerton *hton, char* path);
  int (*panic)(handlerton *hton, enum ha_panic_function flag);
  int (*start_consistent_snapshot)(handlerton *hton, THD *thd);
  bool (*flush_logs)(handlerton *hton, bool binlog_group_flush);
  bool (*show_status)(handlerton *hton, THD *thd, stat_print_fn *print, enum ha_stat_type stat);
  uint (*partition_flags)();
  int (*get_tablespace)(THD* thd, LEX_CSTRING db_name, LEX_CSTRING table_name, LEX_CSTRING *tablespace_name);
  int (*alter_tablespace)(handlerton *hton, THD *thd, st_alter_tablespace *ts_info);
  int (*fill_is_table)(handlerton *hton, THD *thd, TABLE_LIST *tables, class Item *cond, enum enum_schema_tables);
  int (*binlog_func)(handlerton *hton, THD *thd, enum_binlog_func fn, void *arg);
  void (*binlog_log_query)(handlerton *hton, THD *thd, enum_binlog_command binlog_command, const char *query, uint query_length, const char *db, const char *table_name);
  int (*release_temporary_latches)(handlerton *hton, THD *thd);
  int (*discover)(handlerton *hton, THD* thd, const char *db, const char *name, uchar **frmblob, size_t *frmlen);
  int (*find_files)(handlerton *hton, THD *thd, const char *db, const char *path, const char *wild, bool dir, List<LEX_STRING> *files);
  int (*table_exists_in_engine)(handlerton *hton, THD* thd, const char *db, const char *name);
  int (*make_pushed_join)(handlerton *hton, THD* thd, const AQP::Join_plan* plan);
  const char* (*system_database)();
  bool (*is_supported_system_table)(const char *db, const char *table_name, bool is_sql_layer_system_table);
  SE_cost_constants *(*get_cost_constants)(uint storage_category);
  void (*replace_native_transaction_in_thd)(THD *thd, void *new_trx_arg, void **ptr_trx_arg);
  bool (*notify_exclusive_mdl)(THD *thd, const MDL_key *mdl_key, ha_notification_type notification_type, bool *victimized);
  bool (*notify_alter_table)(THD *thd, const MDL_key *mdl_key, ha_notification_type notification_type);
  bool (*rotate_encryption_master_key)(void);
  bool (*is_reserved_db_name)(handlerton *hton, const char *name);
}
```
