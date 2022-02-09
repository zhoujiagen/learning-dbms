# `sql`

|File|Line|Description|Progress|
|:---|---:|:---|:---|
| [abstract_query_plan.cc](#abstract_query_plancc)                        |   494 |||
| [abstract_query_plan.h](#abstract_query_planh)                          |   297 |||
| [add_errmsg](#add_errmsg)                                               |    38 |||
| [aggregate_check.cc](#aggregate_checkcc)                                |  1201 |||
| [aggregate_check.h](#aggregate_checkh)                                  |   686 |||
| [atomic_class.h](#atomic_classh)                                        |   102 |||
| [binlog.cc](#binlogcc)                                                  | 12344 |||
| [binlog.h](#binlogh)                                                    |  1106 |||
| [bootstrap.cc](#bootstrapcc)                                            |   356 |||
| [bootstrap.h](#bootstraph)                                              |    15 |||
| [bootstrap_impl.h](#bootstrap_implh)                                    |    55 |||
| [bounded_queue.h](#bounded_queueh)                                      |   105 |||
| [client_settings.h](#client_settingsh)                                  |    39 |||
| [command_service.cc](#command_servicecc)                                |    60 |||
| [datadict.cc](#datadictcc)                                              |   174 |||
| [datadict.h](#datadicth)                                                |    23 |||
| [debug_sync.cc](#debug_synccc)                                          |  2126 |||
| [debug_sync.h](#debug_synch)                                            |    39 |||
| [derror.cc](#derrorcc)                                                  |   237 | read language-dependent message file. ||
| [derror.h](#derrorh)                                                    |    67 |-||
| [des_key_file.cc](#des_key_filecc)                                      |    89 | load DES keys from plaintext file. ||
| [des_key_file.h](#des_key_fileh)                                        |    21 |-||
| [discover.cc](#discovercc)                                              |   119 | Functions for discovery of `.frm` file from handler. ||
| [discover.h](#discoverh)                                                |     5 |-||
| [discrete_interval.h](#discrete_intervalh)                              |   194 |||
| [dynamic_ids.cc](#dynamic_idscc)                                        |    51 |||
| [dynamic_ids.h](#dynamic_idsh)                                          |    17 |||
| [event_data_objects.cc](#event_data_objectscc)                          |  1564 |||
| [event_data_objects.h](#event_data_objectsh)                            |   215 |||
| [event_db_repository.cc](#event_db_repositorycc)                        |  1276 |||
| [event_db_repository.h](#event_db_repositoryh)                          |   120 |||
| [event_parse_data.cc](#event_parse_datacc)                              |   564 |||
| [event_parse_data.h](#event_parse_datah)                                |   113 |||
| [event_queue.cc](#event_queuecc)                                        |   794 |||
| [event_queue.h](#event_queueh)                                          |   168 |||
| [event_scheduler.cc](#event_schedulercc)                                |   863 |||
| [event_scheduler.h](#event_schedulerh)                                  |   140 |||
| [events.cc](#eventscc)                                                  |  1222 |||
| [events.h](#eventsh)                                                    |   143 |||
| [field.cc](#fieldcc)                                                    | 11604 | defines all storage methods MySQL uses to store field information into records that are then passed to handlers. ||
| [field.h](#fieldh)                                                      |  4700 |-||
| [field_conv.cc](#field_convcc)                                          |  1073 | functions to copy data between fields. ||
| [filesort.cc](#filesortcc)                                              |  2619 | sort a result set, using memory or temporary files. ||
| [filesort.h](#filesorth)                                                |    64 |-||
| [filesort_utils.cc](#filesort_utilscc)                                  |   250 |-||
| [filesort_utils.h](#filesort_utilsh)                                    |   263 |-||
| [gen_lex_hash.cc](#gen_lex_hashcc)                                      |   357 | Knuth's algorithm from Vol 3 Sorting and Searching, Chapter 6.3; used to search for SQL keywords in a query. ||
| [gen_lex_token.cc](#gen_lex_tokencc)                                    |   385 |||
| [geometry_rtree.cc](#geometry_rtreecc)                                  |    82 |||
| [gis_bg_traits.h](#gis_bg_traitsh)                                      |   549 |||
| [gstream.cc](#gstreamcc)                                                |   104 | `GTextReadStream`, used to read GIS objects. ||
| [gstream.h](#gstreamh)                                                  |    73 |-||
| [ha_ndb_ddl_fk.cc](#ha_ndb_ddl_fkcc)                                    |  2711 |||
| [ha_ndb_index_stat.cc](#ha_ndb_index_statcc)                            |  2985 |||
| [ha_ndb_index_stat.h](#ha_ndb_index_stath)                              |    55 |||
| [ha_ndbcluster.cc](#ha_ndbclustercc)                                    | 19456 |||
| [ha_ndbcluster.h](#ha_ndbclusterh)                                      |   733 |||
| [ha_ndbcluster_binlog.cc](#ha_ndbcluster_binlogcc)                      |  7261 |||
| [ha_ndbcluster_binlog.h](#ha_ndbcluster_binlogh)                        |   106 |||
| [ha_ndbcluster_cond.cc](#ha_ndbcluster_condcc)                          |  1786 |||
| [ha_ndbcluster_cond.h](#ha_ndbcluster_condh)                            |   711 |||
| [ha_ndbcluster_connection.cc](#ha_ndbcluster_connectioncc)              |   445 |||
| [ha_ndbcluster_connection.h](#ha_ndbcluster_connectionh)                |    21 |||
| [ha_ndbcluster_glue.h](#ha_ndbcluster_glueh)                            |   141 |||
| [ha_ndbcluster_push.cc](#ha_ndbcluster_pushcc)                          |  1692 |||
| [ha_ndbcluster_push.h](#ha_ndbcluster_pushh)                            |   341 |||
| [ha_ndbcluster_tables.h](#ha_ndbcluster_tablesh)                        |     2 |||
| [ha_ndbinfo.cc](#ha_ndbinfocc)                                          |   863 |||
| [ha_ndbinfo.h](#ha_ndbinfoh)                                            |    75 |||
| [handler.cc](#handlercc)                                                |  8856 | handler-calling functions. ||
| [handler.h](#handlerh)                                                  |  4173 |-||
| [hash_filo.h](#hash_filoh)                                              |   173 | static-sized hash tables, used to store info like hostname -> ip tables in a FIFO manner. ||
| [hostname.cc](#hostnamecc)                                              |   998 | Given IP, return hostname. ||
| [hostname.h](#hostnameh)                                                |   165 |-||
| [init.cc](#initcc)                                                      |    31 | Init and dummy functions for interface with unireg. ||
| [init.h](#inith)                                                        |     4 |-||
| [inplace_vector.h](#inplace_vectorh)                                    |   303 |||
| [item.cc](#itemcc)                                                      | 11015 | `Item` functions. ||
| [item.h](#itemh)                                                        |  5666 |-||
| [item_buff.cc](#item_buffcc)                                            |   253 | Buffers to save and compare item values. ||
| [item_cmpfunc.cc](#item_cmpfunccc)                                      |  7958 | Definition of all compare functions. ||
| [item_cmpfunc.h](#item_cmpfunch)                                        |  2317 |-||
| [item_create.cc](#item_createcc)                                        |  8117 | Create an item. Used by `lex.h` . ||
| [item_create.h](#item_createh)                                          |   169 |-||
| [item_func.cc](#item_funccc)                                            |  8916 | Numerical functions. ||
| [item_func.h](#item_funch)                                              |  2872 |||
| [item_geofunc.cc](#item_geofunccc)                                      |  5122 |||
| [item_geofunc.h](#item_geofunch)                                        |  1138 |||
| [item_geofunc_buffer.cc](#item_geofunc_buffercc)                        |   655 |||
| [item_geofunc_internal.cc](#item_geofunc_internalcc)                    |   687 |||
| [item_geofunc_internal.h](#item_geofunc_internalh)                      |   285 |||
| [item_geofunc_relchecks.cc](#item_geofunc_relcheckscc)                  |  1316 |||
| [item_geofunc_relchecks_bgwrap.cc](#item_geofunc_relchecks_bgwrapcc)    |  1654 |||
| [item_geofunc_relchecks_bgwrap.h](#item_geofunc_relchecks_bgwraph)      |   136 |||
| [item_geofunc_setops.cc](#item_geofunc_setopscc)                        |  3741 |||
| [item_inetfunc.cc](#item_inetfunccc)                                    |   858 |||
| [item_inetfunc.h](#item_inetfunch)                                      |   237 |||
| [item_json_func.cc](#item_json_funccc)                                  |  3696 |||
| [item_json_func.h](#item_json_funch)                                    |   895 |||
| [item_row.cc](#item_rowcc)                                              |   225 | Row items for comparing rows and for `IN` on rows. ||
| [item_row.h](#item_rowh)                                                |   114 |-||
| [item_strfunc.cc](#item_strfunccc)                                      |  5115 | String functions. ||
| [item_strfunc.h](#item_strfunch)                                        |  1316 |-||
| [item_subselect.cc](#item_subselectcc)                                  |  4187 | Subqueries. ||
| [item_subselect.h](#item_subselecth)                                    |   832 |-||
| [item_sum.cc](#item_sumcc)                                              |  4097 | Set functions (`SUM()`, `AVG()`, etc.). ||
| [item_sum.h](#item_sumh)                                                |  1601 |-||
| [item_timefunc.cc](#item_timefunccc)                                    |  3412 | Date/time functions, for example, week of year. ||
| [item_timefunc.h](#item_timefunch)                                      |  1716 |-||
| [item_xmlfunc.cc](#item_xmlfunccc)                                      |  2370 |||
| [item_xmlfunc.h](#item_xmlfunch)                                        |    63 |||
| [json_binary.cc](#json_binarycc)                                        |  1379 |||
| [json_binary.h](#json_binaryh)                                          |   274 |||
| [json_dom.cc](#json_domcc)                                              |  4034 |||
| [json_dom.h](#json_domh)                                                |  1563 |||
| [json_path.cc](#json_pathcc)                                            |   790 |||
| [json_path.h](#json_pathh)                                              |   369 |||
| [key.cc](#keycc)                                                        |   708 | Functions to create keys from records and compare a key to a key in a record. ||
| [key.h](#keyh)                                                          |   280 |-||
| [keycaches.cc](#keycachescc)                                            |   116 |||
| [keycaches.h](#keycachesh)                                              |    56 |||
| [keyring_service.cc](#keyring_servicecc)                                |   140 |||
| [lex.h](#lexh)                                                          |   733 |||
| [lex_symbol.h](#lex_symbolh)                                            |    28 |||
| [lock.cc](#lockcc)                                                      |  1225 | Locks. ||
| [lock.h](#lockh)                                                        |    44 |-||
| [locking_service.cc](#locking_servicecc)                                |   191 |||
| [locking_service.def](#locking_servicedef)                              |    30 |||
| [locking_service.h](#locking_serviceh)                                  |    47 |||
| [locking_service_udf.cc](#locking_service_udfcc)                        |   132 |||
| [log.cc](#logcc)                                                        |  2180 | Logs. ||
| [log.h](#logh)                                                          |   946 |-||
| [log_event.cc](#log_eventcc)                                            | 14457 | Log event (a binary log consists of a stream of log events). ||
| [log_event.h](#log_eventh)                                              |  4482 |-||
| [log_event_old.cc](#log_event_oldcc)                                    |  2903 |||
| [log_event_old.h](#log_event_oldh)                                      |   545 |||
| [main.cc](#maincc)                                                      |     7 | Entry point for `mysqld`. ||
| [malloc_allocator.h](#malloc_allocatorh)                                |   121 |||
| [mdl.cc](#mdlcc)                                                        |  4903 |||
| [mdl.h](#mdlh)                                                          |  1190 |||
| [mem_root_array.h](#mem_root_arrayh)                                    |   262 |||
| [memroot_allocator.h](#memroot_allocatorh)                              |   131 |||
| [merge_sort.h](#merge_sorth)                                            |   126 |||
| [message.h](#messageh)                                                  |    58 |||
| [message.mc](#messagemc)                                                |    16 |||
| [message.rc](#messagerc)                                                |    24 |||
| [mf_iocache.cc](#mf_iocachecc)                                          |    71 | Caching of (sequential) reads and writes. ||
| [migrate_keyring.cc](#migrate_keyringcc)                                |   431 |||
| [migrate_keyring.h](#migrate_keyringh)                                  |   106 |||
| [my_decimal.cc](#my_decimalcc)                                          |   382 | New decimal and numeric code. ||
| [my_decimal.h](#my_decimalh)                                            |   524 |-||
| [mysqld.cc](#mysqldcc)                                                  |  9573 | Starts `mysqld`, handling of signals and connections. ||
| [mysqld.h](#mysqldh)                                                    |  1002 |-||
| [mysqld_daemon.cc](#mysqld_daemoncc)                                    |   129 |||
| [mysqld_daemon.h](#mysqld_daemonh)                                      |     8 |||
| [mysqld_suffix.h](#mysqld_suffixh)                                      |    15 |||
| [mysqld_thd_manager.cc](#mysqld_thd_managercc)                          |   315 |||
| [mysqld_thd_manager.h](#mysqld_thd_managerh)                            |   261 |||
| [named_pipe.cc](#named_pipecc)                                          |   318 |||
| [named_pipe.h](#named_pipeh)                                            |    20 |||
| [ndb_anyvalue.cc](#ndb_anyvaluecc)                                      |   165 |||
| [ndb_anyvalue.h](#ndb_anyvalueh)                                        |    27 |||
| [ndb_binlog_extra_row_info.cc](#ndb_binlog_extra_row_infocc)            |   168 |||
| [ndb_binlog_extra_row_info.h](#ndb_binlog_extra_row_infoh)              |    64 |||
| [ndb_binlog_thread.cc](#ndb_binlog_threadcc)                            |    -1 |||
| [ndb_binlog_thread.h](#ndb_binlog_threadh)                              |    17 |||
| [ndb_component.cc](#ndb_componentcc)                                    |   171 |||
| [ndb_component.h](#ndb_componenth)                                      |    92 |||
| [ndb_conflict.cc](#ndb_conflictcc)                                      |  2940 |||
| [ndb_conflict.h](#ndb_conflicth)                                        |   528 |||
| [ndb_conflict_trans.cc](#ndb_conflict_transcc)                          |   771 |||
| [ndb_conflict_trans.h](#ndb_conflict_transh)                            |   318 |||
| [ndb_dist_priv_util.h](#ndb_dist_priv_utilh)                            |    53 |||
| [ndb_event_data.cc](#ndb_event_datacc)                                  |   135 |||
| [ndb_event_data.h](#ndb_event_datah)                                    |    32 |||
| [ndb_find_files_list.cc](#ndb_find_files_listcc)                        |   112 |||
| [ndb_find_files_list.h](#ndb_find_files_listh)                          |    56 |||
| [ndb_global_schema_lock.cc](#ndb_global_schema_lockcc)                  |   449 |||
| [ndb_global_schema_lock.h](#ndb_global_schema_lockh)                    |     5 |||
| [ndb_global_schema_lock_guard.h](#ndb_global_schema_lock_guardh)        |    17 |||
| [ndb_local_connection.cc](#ndb_local_connectioncc)                      |   393 |||
| [ndb_local_connection.h](#ndb_local_connectionh)                        |    58 |||
| [ndb_local_schema.cc](#ndb_local_schemacc)                              |   278 |||
| [ndb_local_schema.h](#ndb_local_schemah)                                |    62 |||
| [ndb_log.cc](#ndb_logcc)                                                |   115 |||
| [ndb_log.h](#ndb_logh)                                                  |    33 |||
| [ndb_mi.cc](#ndb_micc)                                                  |   104 |||
| [ndb_mi.h](#ndb_mih)                                                    |    30 |||
| [ndb_name_util.cc](#ndb_name_utilcc)                                    |    54 |||
| [ndb_name_util.h](#ndb_name_utilh)                                      |     7 |||
| [ndb_ndbapi_util.cc](#ndb_ndbapi_utilcc)                                |    40 |||
| [ndb_ndbapi_util.h](#ndb_ndbapi_utilh)                                  |    29 |||
| [ndb_repl_tab.cc](#ndb_repl_tabcc)                                      |   541 |||
| [ndb_repl_tab.h](#ndb_repl_tabh)                                        |   235 |||
| [ndb_schema_dist.cc](#ndb_schema_distcc)                                |    58 |||
| [ndb_schema_dist.h](#ndb_schema_disth)                                  |    58 |||
| [ndb_schema_object.cc](#ndb_schema_objectcc)                            |   110 |||
| [ndb_schema_object.h](#ndb_schema_objecth)                              |    34 |||
| [ndb_share.cc](#ndb_sharecc)                                            |   251 |||
| [ndb_share.h](#ndb_shareh)                                              |   265 |||
| [ndb_table_guard.h](#ndb_table_guardh)                                  |    66 |||
| [ndb_tdc.cc](#ndb_tdccc)                                                |    56 |||
| [ndb_tdc.h](#ndb_tdch)                                                  |    13 |||
| [ndb_thd.cc](#ndb_thdcc)                                                |    75 |||
| [ndb_thd.h](#ndb_thdh)                                                  |    47 |||
| [ndb_thd_ndb.cc](#ndb_thd_ndbcc)                                        |   126 |||
| [ndb_thd_ndb.h](#ndb_thd_ndbh)                                          |   143 |||
| [ndb_util_thread.h](#ndb_util_threadh)                                  |    21 |||
| [net_serv.cc](#net_servcc)                                              |  1055 | Read/write of packets on a network socket. ||
| [nt_servc.cc](#nt_servccc)                                              |   543 | Initialize/register/remove an `NTService` . ||
| [nt_servc.h](#nt_servch)                                                |    89 |-||
| [opt_costconstantcache.cc](#opt_costconstantcachecc)                    |   490 |||
| [opt_costconstantcache.h](#opt_costconstantcacheh)                      |   189 |||
| [opt_costconstants.cc](#opt_costconstantscc)                            |   383 |||
| [opt_costconstants.h](#opt_costconstantsh)                              |   546 |||
| [opt_costmodel.cc](#opt_costmodelcc)                                    |    89 |||
| [opt_costmodel.h](#opt_costmodelh)                                      |   403 |||
| [opt_explain.cc](#opt_explaincc)                                        |  2476 |||
| [opt_explain.h](#opt_explainh)                                          |   170 |||
| [opt_explain_format.h](#opt_explain_formath)                            |   569 |||
| [opt_explain_json.cc](#opt_explain_jsoncc)                              |  2044 |||
| [opt_explain_json.h](#opt_explain_jsonh)                                |    31 |||
| [opt_explain_traditional.cc](#opt_explain_traditionalcc)                |   239 |||
| [opt_explain_traditional.h](#opt_explain_traditionalh)                  |    31 |||
| [opt_hints.cc](#opt_hintscc)                                            |   381 |||
| [opt_hints.h](#opt_hintsh)                                              |   499 |||
| [opt_range.cc](#opt_rangecc)                                            | 15269 | Range of keys. ||
| [opt_range.h](#opt_rangeh)                                              |  1020 |-||
| [opt_statistics.cc](#opt_statisticscc)                                  |    95 |||
| [opt_statistics.h](#opt_statisticsh)                                    |    21 |||
| [opt_sum.cc](#opt_sumcc)                                                |  1101 | Optimize functions in presence of (implied) `GROUP BY` . ||
| [opt_trace.cc](#opt_tracecc)                                            |  1335 |||
| [opt_trace.h](#opt_traceh)                                              |  1243 |||
| [opt_trace2server.cc](#opt_trace2servercc)                              |   586 |||
| [opt_trace_Doxyfile](#opt_trace_Doxyfile)                                |  1611 |||
| [opt_trace_context.h](#opt_trace_contexth)                              |   410 |||
| [parse_file.cc](#parse_filecc)                                          |   895 | Text `.frm` files management routines. ||
| [parse_file.h](#parse_fileh)                                            |    99 |||
| [parse_location.h](#parse_locationh)                                    |    55 |||
| [parse_tree_helpers.cc](#parse_tree_helperscc)                          |   413 |||
| [parse_tree_helpers.h](#parse_tree_helpersh)                            |   181 |||
| [parse_tree_hints.cc](#parse_tree_hintscc)                              |   425 |||
| [parse_tree_hints.h](#parse_tree_hintsh)                                |   260 |||
| [parse_tree_items.cc](#parse_tree_itemscc)                              |   296 |||
| [parse_tree_items.h](#parse_tree_itemsh)                                |  1035 |||
| [parse_tree_node_base.cc](#parse_tree_node_basecc)                      |    21 |||
| [parse_tree_node_base.h](#parse_tree_node_baseh)                        |   188 |||
| [parse_tree_nodes.cc](#parse_tree_nodescc)                              |   996 |||
| [parse_tree_nodes.h](#parse_tree_nodesh)                                |  2657 |||
| [parser_service.cc](#parser_servicecc)                                  |   375 |||
| [partition_element.h](#partition_elementh)                              |   136 |||
| [partition_info.cc](#partition_infocc)                                  |  3321 |||
| [partition_info.h](#partition_infoh)                                    |   554 |||
| [plistsort.c](#plistsortc)                                              |   173 |||
| [procedure.cc](#procedurecc)                                            |    19 | Procedure interface, as used in `SELECT * FROM Table_name PROCEDURE ANALYSE()` .||
| [procedure.h](#procedureh)                                              |    92 |-||
| [protocol.h](#protocolh)                                                |   286 | Low level functions for PACKING data that is sent to client; actual sending done with `net_serv.cc` .||
| [protocol_callback.cc](#protocol_callbackcc)                            |   532 |||
| [protocol_callback.h](#protocol_callbackh)                              |   379 |||
| [protocol_classic.cc](#protocol_classiccc)                              |  1896 |||
| [protocol_classic.h](#protocol_classich)                                |   271 |||
| [query_options.h](#query_optionsh)                                      |    97 |||
| [records.cc](#recordscc)                                                |   794 | Functions for easy reading of records, possible through a cache. ||
| [records.h](#recordsh)                                                  |    69 |-||
| [replication.h](#replicationh)                                          |   818 |||
| [rpl_binlog_sender.cc](#rpl_binlog_sendercc)                            |  1371 |||
| [rpl_binlog_sender.h](#rpl_binlog_senderh)                              |   439 |||
| [rpl_channel_service_interface.cc](#rpl_channel_service_interfacecc)    |  1029 |||
| [rpl_channel_service_interface.h](#rpl_channel_service_interfaceh)      |   381 |||
| [rpl_constants.h](#rpl_constantsh)                                      |    47 |||
| [rpl_context.cc](#rpl_contextcc)                                        |   172 |||
| [rpl_context.h](#rpl_contexth)                                          |   248 |||
| [rpl_filter.cc](#rpl_filtercc)                                          |  1084 |||
| [rpl_filter.h](#rpl_filterh)                                            |   178 |||
| [rpl_group_replication.cc](#rpl_group_replicationcc)                    |   389 |||
| [rpl_group_replication.h](#rpl_group_replicationh)                      |    32 |||
| [rpl_gtid.h](#rpl_gtidh)                                                |  3681 |||
| [rpl_gtid_execution.cc](#rpl_gtid_executioncc)                          |   612 |||
| [rpl_gtid_misc.cc](#rpl_gtid_misccc)                                    |   270 |||
| [rpl_gtid_mutex_cond_array.cc](#rpl_gtid_mutex_cond_arraycc)            |    75 |||
| [rpl_gtid_owned.cc](#rpl_gtid_ownedcc)                                  |   173 |||
| [rpl_gtid_persist.cc](#rpl_gtid_persistcc)                              |   965 |||
| [rpl_gtid_persist.h](#rpl_gtid_persisth)                                |   347 |||
| [rpl_gtid_set.cc](#rpl_gtid_setcc)                                      |  1549 |||
| [rpl_gtid_sid_map.cc](#rpl_gtid_sid_mapcc)                              |   172 |||
| [rpl_gtid_specification.cc](#rpl_gtid_specificationcc)                  |    82 |||
| [rpl_gtid_state.cc](#rpl_gtid_statecc)                                  |  1034 |||
| [rpl_handler.cc](#rpl_handlercc)                                        |  1006 |||
| [rpl_handler.h](#rpl_handlerh)                                          |   312 |||
| [rpl_info.cc](#rpl_infocc)                                              |    74 |||
| [rpl_info.h](#rpl_infoh)                                                |   189 |||
| [rpl_info_dummy.cc](#rpl_info_dummycc)                                  |   192 |||
| [rpl_info_dummy.h](#rpl_info_dummyh)                                    |    58 |||
| [rpl_info_factory.cc](#rpl_info_factorycc)                              |  1419 |||
| [rpl_info_factory.h](#rpl_info_factoryh)                                |   110 |||
| [rpl_info_file.cc](#rpl_info_filecc)                                    |   649 |||
| [rpl_info_file.h](#rpl_info_fileh)                                      |   108 |||
| [rpl_info_handler.cc](#rpl_info_handlercc)                              |    40 |||
| [rpl_info_handler.h](#rpl_info_handlerh)                                |   419 |||
| [rpl_info_table.cc](#rpl_info_tablecc)                                  |   828 |||
| [rpl_info_table.h](#rpl_info_tableh)                                    |   143 |||
| [rpl_info_table_access.cc](#rpl_info_table_accesscc)                    |   348 |||
| [rpl_info_table_access.h](#rpl_info_table_accessh)                      |    46 |||
| [rpl_info_values.cc](#rpl_info_valuescc)                                |    27 |||
| [rpl_info_values.h](#rpl_info_valuesh)                                  |    25 |||
| [rpl_injector.cc](#rpl_injectorcc)                                      |   303 |||
| [rpl_injector.h](#rpl_injectorh)                                        |   377 |||
| [rpl_master.cc](#rpl_mastercc)                                          |   751 |||
| [rpl_master.h](#rpl_masterh)                                            |    94 |||
| [rpl_mi.cc](#rpl_micc)                                                  |   624 |||
| [rpl_mi.h](#rpl_mih)                                                    |   492 |||
| [rpl_msr.cc](#rpl_msrcc)                                                |   224 |||
| [rpl_msr.h](#rpl_msrh)                                                  |   400 |||
| [rpl_mts_submode.cc](#rpl_mts_submodecc)                                |  1017 |||
| [rpl_mts_submode.h](#rpl_mts_submodeh)                                  |   179 |||
| [rpl_record.cc](#rpl_recordcc)                                          |   557 |||
| [rpl_record.h](#rpl_recordh)                                            |    22 |||
| [rpl_record_old.cc](#rpl_record_oldcc)                                  |   174 |||
| [rpl_record_old.h](#rpl_record_oldh)                                    |    22 |||
| [rpl_reporting.cc](#rpl_reportingcc)                                    |   158 |||
| [rpl_reporting.h](#rpl_reportingh)                                      |   156 |||
| [rpl_rli.cc](#rpl_rlicc)                                                |  3036 |||
| [rpl_rli.h](#rpl_rlih)                                                  |  1348 |||
| [rpl_rli_pdb.cc](#rpl_rli_pdbcc)                                        |  2736 |||
| [rpl_rli_pdb.h](#rpl_rli_pdbh)                                          |   783 |||
| [rpl_slave.cc](#rpl_slavecc)                                            | 11799 | Procedures for a slave in a master/slave (replication) relation. ||
| [rpl_slave.h](#rpl_slaveh)                                              |   449 |||
| [rpl_slave_commit_order_manager.cc](#rpl_slave_commit_order_managercc)  |   147 |||
| [rpl_slave_commit_order_manager.h](#rpl_slave_commit_order_managerh)    |   198 |||
| [rpl_table_access.cc](#rpl_table_accesscc)                              |   145 |||
| [rpl_table_access.h](#rpl_table_accessh)                                |   101 |||
| [rpl_tblmap.cc](#rpl_tblmapcc)                                          |   160 |||
| [rpl_tblmap.h](#rpl_tblmaph)                                            |    94 |||
| [rpl_transaction_ctx.cc](#rpl_transaction_ctxcc)                        |    90 |||
| [rpl_transaction_ctx.h](#rpl_transaction_ctxh)                          |    72 |||
| [rpl_transaction_write_set_ctx.cc](#rpl_transaction_write_set_ctxcc)    |   246 |||
| [rpl_transaction_write_set_ctx.h](#rpl_transaction_write_set_ctxh)      |   120 |||
| [rpl_trx_boundary_parser.cc](#rpl_trx_boundary_parsercc)                |   448 |||
| [rpl_trx_boundary_parser.h](#rpl_trx_boundary_parserh)                  |   189 |||
| [rpl_trx_tracking.cc](#rpl_trx_trackingcc)                              |   380 |||
| [rpl_trx_tracking.h](#rpl_trx_trackingh)                                |   216 |||
| [rpl_utility.cc](#rpl_utilitycc)                                        |  1352 |||
| [rpl_utility.h](#rpl_utilityh)                                          |   440 |||
| [rpl_write_set_handler.cc](#rpl_write_set_handlercc)                    |   875 |||
| [rpl_write_set_handler.h](#rpl_write_set_handlerh)                      |    22 |||
| [rules_table_service.cc](#rules_table_servicecc)                        |   190 |||
| [select_lex_visitor.cc](#select_lex_visitorcc)                          |     5 |||
| [select_lex_visitor.h](#select_lex_visitorh)                            |    32 |||
| [session_tracker.cc](#session_trackercc)                                |  1648 |||
| [session_tracker.h](#session_trackerh)                                  |   299 |||
| [set_var.cc](#set_varcc)                                                |   997 | Set and retrieve MySQL user variables. ||
| [set_var.h](#set_varh)                                                  |   361 |-||
| [signal_handler.cc](#signal_handlercc)                                  |   211 |||
| [sp.cc](#spcc)                                                          |  2818 | DB storage of stored procedures and functions. ||
| [sp.h](#sph)                                                            |   203 |-||
| [sp_cache.cc](#sp_cachecc)                                              |   229 |||
| [sp_cache.h](#sp_cacheh)                                                |    40 |||
| [sp_head.cc](#sp_headcc)                                                |  2286 |||
| [sp_head.h](#sp_headh)                                                  |  1051 |||
| [sp_instr.cc](#sp_instrcc)                                              |  1917 |||
| [sp_instr.h](#sp_instrh)                                                |  1620 |||
| [sp_pcontext.cc](#sp_pcontextcc)                                        |   544 |||
| [sp_pcontext.h](#sp_pcontexth)                                          |   572 |||
| [sp_rcontext.cc](#sp_rcontextcc)                                        |   607 |||
| [sp_rcontext.h](#sp_rcontexth)                                          |   422 |||
| [spatial.cc](#spatialcc)                                                |  5167 | Geometry stuff (lines, points, etc.). ||
| [spatial.h](#spatialh)                                                  |  2751 |-||
| [sql_admin.cc](#sql_admincc)                                            |  1346 |||
| [sql_admin.h](#sql_adminh)                                              |   152 |||
| [sql_alloc.h](#sql_alloch)                                              |    36 |||
| [sql_alloc_error_handler.cc](#sql_alloc_error_handlercc)                |    33 |||
| [sql_alter.cc](#sql_altercc)                                            |   363 |||
| [sql_alter.h](#sql_alterh)                                              |   498 |||
| [sql_alter_instance.cc](#sql_alter_instancecc)                          |    93 |||
| [sql_alter_instance.h](#sql_alter_instanceh)                            |    28 |||
| [sql_analyse.cc](#sql_analysecc)                                        |  1255 | Implements the `PROCEDURE ANALYSE()`, which analyzes a query result and returns the 'optimal' data type for each result column. ||
| [sql_analyse.h](#sql_analyseh)                                          |   353 |-||
| [sql_array.h](#sql_arrayh)                                              |    98 |||
| [sql_audit.cc](#sql_auditcc)                                            |  1477 |||
| [sql_audit.h](#sql_audith)                                              |   269 |||
| [sql_base.cc](#sql_basecc)                                              | 10438 | Basic functions needed by many modules, like opening and closing tables with table cache management. ||
| [sql_base.h](#sql_baseh)                                                |   773 |-||
| [sql_binlog.cc](#sql_binlogcc)                                          |   300 |||
| [sql_binlog.h](#sql_binlogh)                                            |     4 |||
| [sql_bitmap.h](#sql_bitmaph)                                            |   178 |||
| [sql_bootstrap.cc](#sql_bootstrapcc)                                    |   101 |||
| [sql_bootstrap.h](#sql_bootstraph)                                      |    31 |||
| [sql_builtin.cc.in](#sql_builtin.ccin)                                  |    44 |||
| [sql_cache.cc](#sql_cachecc)                                            |  5009 | SQL query cache, with long comments about how caching works. ||
| [sql_cache.h](#sql_cacheh)                                              |   529 |-||
| [sql_callback.h](#sql_callbackh)                                        |    24 |||
| [sql_class.cc](#sql_classcc)                                            |  4852 | SQL class; implements the SQL base classes, of which `THD` (THREAD object) is the most important. ||
| [sql_class.h](#sql_classh)                                              |  5705 |-||
| [sql_client.cc](#sql_clientcc)                                          |    27 | A function called by `my_net_init()` to set some check variables. ||
| [sql_cmd.h](#sql_cmdh)                                                  |    82 |||
| [sql_cmd_dml.h](#sql_cmd_dmlh)                                          |    35 |||
| [sql_connect.cc](#sql_connectcc)                                        |   935 |||
| [sql_connect.h](#sql_connecth)                                          |    81 |||
| [sql_const.h](#sql_consth)                                              |   331 |||
| [sql_crypt.cc](#sql_cryptcc)                                            |    55 | Encode / decode. ||
| [sql_crypt.h](#sql_crypth)                                              |    26 |-||
| [sql_cursor.cc](#sql_cursorcc)                                          |   418 | Server side cursor. ||
| [sql_cursor.h](#sql_cursorh)                                            |    43 |-||
| [sql_data_change.cc](#sql_data_changecc)                                |   152 |||
| [sql_data_change.h](#sql_data_changeh)                                  |   305 |||
| [sql_db.cc](#sql_dbcc)                                                  |  1959 | Create / drop database. ||
| [sql_db.h](#sql_dbh)                                                    |    33 |-||
| [sql_delete.cc](#sql_deletecc)                                          |  1458 | The `DELETE` statement. ||
| [sql_delete.h](#sql_deleteh)                                            |   101 |-||
| [sql_derived.cc](#sql_derivedcc)                                        |   335 | Derived tables. ||
| [sql_derived.h](#sql_derivedh)                                          |     0 |-||
| [sql_digest.cc](#sql_digestcc)                                          |   688 |||
| [sql_digest.h](#sql_digesth)                                            |   112 |||
| [sql_digest_stream.h](#sql_digest_streamh)                              |    32 |||
| [sql_do.cc](#sql_docc)                                                  |    60 | The `DO` statement. ||
| [sql_do.h](#sql_doh)                                                    |    19 |-||
| [sql_error.cc](#sql_errorcc)                                            |  1090 | Errors and warnings. ||
| [sql_error.h](#sql_errorh)                                              |   796 |-||
| [sql_exception_handler.cc](#sql_exception_handlercc)                    |    70 |||
| [sql_exception_handler.h](#sql_exception_handlerh)                      |    39 |||
| [sql_executor.cc](#sql_executorcc)                                      |  4754 |||
| [sql_executor.h](#sql_executorh)                                        |   662 |||
| [sql_get_diagnostics.cc](#sql_get_diagnosticscc)                        |   343 |||
| [sql_get_diagnostics.h](#sql_get_diagnosticsh)                          |   300 |||
| [sql_handler.cc](#sql_handlercc)                                        |  1108 | Implements the `HANDLER` interface, which gives direct access to rows in MyISAM and InnoDB. ||
| [sql_handler.h](#sql_handlerh)                                          |   120 |-||
| [sql_help.cc](#sql_helpcc)                                              |   830 | The `HELP` statement. ||
| [sql_help.h](#sql_helph)                                                |     9 |-||
| [sql_hints.yy](#sql_hintsyy)                                            |   418 |||
| [sql_hset.h](#sql_hseth)                                                |    81 |||
| [sql_initialize.cc](#sql_initializecc)                                  |   331 |||
| [sql_initialize.h](#sql_initializeh)                                    |    21 |||
| [sql_insert.cc](#sql_insertcc)                                          |  3246 | The `INSERT` statement. ||
| [sql_insert.h](#sql_inserth)                                            |   295 |||
| [sql_join_buffer.cc](#sql_join_buffercc)                                |  3640 | Join buffer. ||
| [sql_join_buffer.h](#sql_join_bufferh)                                  |   876 |-||
| [sql_lex.cc](#sql_lexcc)                                                |  4903 | Does lexical analysis of a query; that is, breaks a query string into pieces and determines the basic type (number, string, keyword, etc.) of each piece. ||
| [sql_lex.h](#sql_lexh)                                                  |  3714 |-||
| [sql_lex_hash.cc](#sql_lex_hashcc)                                      |    87 |||
| [sql_lex_hash.h](#sql_lex_hashh)                                        |    29 |||
| [sql_lex_hints.cc](#sql_lex_hintscc)                                    |   145 |||
| [sql_lex_hints.h](#sql_lex_hintsh)                                      |   457 |||
| [sql_list.cc](#sql_listcc)                                              |    49 | Simple intrusive linked list. ||
| [sql_list.h](#sql_listh)                                                |   813 |-||
| [sql_load.cc](#sql_loadcc)                                              |  2286 | The `LOAD DATA` statement. ||
| [sql_load.h](#sql_loadh)                                                |    14 |||
| [sql_locale.cc](#sql_localecc)                                          |  3497 |||
| [sql_locale.h](#sql_localeh)                                            |    54 |||
| [sql_manager.cc](#sql_managercc)                                        |   102 | Maintenance tasks, for example, flushing the buffers periodically; used with BDB table logs. ||
| [sql_manager.h](#sql_managerh)                                          |     3 |-||
| [sql_opt_exec_shared.h](#sql_opt_exec_sharedh)                          |   505 |||
| [sql_optimizer.cc](#sql_optimizercc)                                    | 11368 |||
| [sql_optimizer.h](#sql_optimizerh)                                      |   886 |||
| [sql_parse.cc](#sql_parsecc)                                            |  7241 | Parse an SQL statement; do initial checks and then jump to the function that should execute the statement. ||
| [sql_parse.h](#sql_parseh)                                              |   145 |-||
| [sql_partition.cc](#sql_partitioncc)                                    |  8464 |||
| [sql_partition.h](#sql_partitionh)                                      |   205 |||
| [sql_partition_admin.cc](#sql_partition_admincc)                        |   808 |||
| [sql_partition_admin.h](#sql_partition_adminh)                          |   158 |||
| [sql_planner.cc](#sql_plannercc)                                        |  4596 |||
| [sql_planner.h](#sql_plannerh)                                          |   203 |||
| [sql_plist.h](#sql_plisth)                                              |   266 |||
| [sql_plugin.cc](#sql_plugincc)                                          |  4433 |||
| [sql_plugin.h](#sql_pluginh)                                            |   173 |||
| [sql_plugin_enum.h](#sql_plugin_enumh)                                  |    18 |||
| [sql_plugin_ref.h](#sql_plugin_refh)                                    |   144 |||
| [sql_plugin_services.h](#sql_plugin_servicesh)                          |   175 |||
| [sql_prepare.cc](#sql_preparecc)                                        |  4632 | Prepare an SQL statement, or use a prepared statement. ||
| [sql_prepare.h](#sql_prepareh)                                          |   473 |-||
| [sql_profile.cc](#sql_profilecc)                                        |   728 |||
| [sql_profile.h](#sql_profileh)                                          |   276 |||
| [sql_query_rewrite.cc](#sql_query_rewritecc)                            |   174 |||
| [sql_query_rewrite.h](#sql_query_rewriteh)                              |    28 |||
| [sql_reload.cc](#sql_reloadcc)                                          |   558 |||
| [sql_reload.h](#sql_reloadh)                                            |     9 |||
| [sql_rename.cc](#sql_renamecc)                                          |   352 | Rename table. ||
| [sql_rename.h](#sql_renameh)                                            |     8 |-||
| [sql_resolver.cc](#sql_resolvercc)                                      |  3747 |||
| [sql_resolver.h](#sql_resolverh)                                        |    31 |||
| [sql_rewrite.cc](#sql_rewritecc)                                        |   834 |||
| [sql_rewrite.h](#sql_rewriteh)                                          |    -2 |||
| [sql_select.cc](#sql_selectcc)                                          |  4423 | Select and join optimization. ||
| [sql_select.h](#sql_selecth)                                            |  1153 |-||
| [sql_servers.cc](#sql_serverscc)                                        |   969 |||
| [sql_servers.h](#sql_serversh)                                          |   242 |||
| [sql_show.cc](#sql_showcc)                                              |  9514 | The `SHOW` statement. ||
| [sql_show.h](#sql_showh)                                                |   241 |||
| [sql_show_status.cc](#sql_show_statuscc)                                |   324 |||
| [sql_show_status.h](#sql_show_statush)                                  |    17 |||
| [sql_signal.cc](#sql_signalcc)                                          |   549 |||
| [sql_signal.h](#sql_signalh)                                            |   174 |||
| [sql_sort.h](#sql_sorth)                                                |   540 |||
| [sql_state.c](#sql_statec)                                              |    60 | Functions to map `mysqld` errno to sqlstate. ||
| [sql_table.cc](#sql_tablecc)                                            | 10775 | The `DROP TABLE` and `ALTER TABLE` statements. ||
| [sql_table.h](#sql_tableh)                                              |   239 |-||
| [sql_tablespace.cc](#sql_tablespacecc)                                  |   207 |||
| [sql_tablespace.h](#sql_tablespaceh)                                    |    32 |||
| [sql_test.cc](#sql_testcc)                                              |   695 | Some debugging information. ||
| [sql_test.h](#sql_testh)                                                |    25 |-||
| [sql_thd_internal_api.cc](#sql_thd_internal_apicc)                      |   122 |||
| [sql_thd_internal_api.h](#sql_thd_internal_apih)                        |    83 |||
| [sql_time.cc](#sql_timecc)                                              |  1711 |||
| [sql_time.h](#sql_timeh)                                                |   281 |||
| [sql_timer.cc](#sql_timercc)                                            |   226 |||
| [sql_timer.h](#sql_timerh)                                              |     8 |||
| [sql_tmp_table.cc](#sql_tmp_tablecc)                                    |  2631 |||
| [sql_tmp_table.h](#sql_tmp_tableh)                                      |    83 |||
| [sql_trigger.cc](#sql_triggercc)                                        |   472 | Triggers. ||
| [sql_trigger.h](#sql_triggerh)                                          |    43 |-||
| [sql_truncate.cc](#sql_truncatecc)                                      |   551 |||
| [sql_truncate.h](#sql_truncateh)                                        |    62 |||
| [sql_udf.cc](#sql_udfcc)                                                |   630 | User-defined functions. ||
| [sql_udf.h](#sql_udfh)                                                  |   123 |-||
| [sql_union.cc](#sql_unioncc)                                            |  1087 | The `UNION` operator. ||
| [sql_union.h](#sql_unionh)                                              |    38 |-||
| [sql_update.cc](#sql_updatecc)                                          |  3060 | The `UPDATE` statement. ||
| [sql_update.h](#sql_updateh)                                            |   115 |-||
| [sql_view.cc](#sql_viewcc)                                              |  2157 | Views. ||
| [sql_view.h](#sql_viewh)                                                |    40 |-||
| [sql_yacc.yy](#sql_yaccyy)                                              | 15529 |||
| [srv_session.cc](#srv_sessioncc)                                        |  1373 |||
| [srv_session.h](#srv_sessionh)                                          |   292 |||
| [srv_session_info_service.cc](#srv_session_info_servicecc)              |   135 |||
| [srv_session_service.cc](#srv_session_servicecc)                        |   176 |||
| [ssl_wrapper_service.cc](#ssl_wrapper_servicecc)                        |   296 |||
| [strfunc.cc](#strfunccc)                                                |   387 | String functions. ||
| [strfunc.h](#strfunch)                                                  |    50 |-||
| [string_service.cc](#string_servicecc)                                  |   146 |||
| [string_service.h](#string_serviceh)                                    |    10 |||
| [sys_vars.cc](#sys_varscc)                                              |  5964 |||
| [sys_vars.h](#sys_varsh)                                                |  2995 |||
| [sys_vars_resource_mgr.cc](#sys_vars_resource_mgrcc)                    |   205 |||
| [sys_vars_resource_mgr.h](#sys_vars_resource_mgrh)                      |    86 |||
| [sys_vars_shared.h](#sys_vars_sharedh)                                  |    75 |||
| [table.cc](#tablecc)                                                    |  7946 | Table metadata retrieval; read the table definition from a `.frm` file and store it in a `TABLE` object. ||
| [table.h](#tableh)                                                      |  3054 |||
| [table_cache.cc](#table_cachecc)                                        |   393 |||
| [table_cache.h](#table_cacheh)                                          |   597 |||
| [table_trigger_dispatcher.cc](#table_trigger_dispatchercc)              |   920 |||
| [table_trigger_dispatcher.h](#table_trigger_dispatcherh)                |   284 |||
| [table_trigger_field_support.h](#table_trigger_field_supporth)          |    31 |||
| [tc_log.cc](#tc_logcc)                                                  |   543 |||
| [tc_log.h](#tc_logh)                                                    |   248 |||
| [tempCodeRunnerFile.cc](#tempCodeRunnerFilecc)                          |   -25 |||
| [thr_malloc.cc](#thr_malloccc)                                          |    93 | Thread-safe interface to `mysys/my_alloc.c` . ||
| [thr_malloc.h](#thr_malloch)                                            |    24 |-||
| [transaction.cc](#transactioncc)                                        |   783 |||
| [transaction.h](#transactionh)                                          |    23 |||
| [transaction_info.cc](#transaction_infocc)                              |   102 |||
| [transaction_info.h](#transaction_infoh)                                |   614 |||
| [trigger.cc](#triggercc)                                                |   808 |||
| [trigger.h](#triggerh)                                                  |   305 |||
| [trigger_chain.cc](#trigger_chaincc)                                    |   218 |||
| [trigger_chain.h](#trigger_chainh)                                      |    43 |||
| [trigger_creation_ctx.cc](#trigger_creation_ctxcc)                      |    74 |||
| [trigger_creation_ctx.h](#trigger_creation_ctxh)                        |    48 |||
| [trigger_def.h](#trigger_defh)                                          |    67 |||
| [trigger_loader.cc](#trigger_loadercc)                                  |   989 |||
| [trigger_loader.h](#trigger_loaderh)                                    |    71 |||
| [tzfile.h](#tzfileh)                                                    |   113 |||
| [tztime.cc](#tztimecc)                                                  |  2601 | `class Time_zone`. ||
| [tztime.h](#tztimeh)                                                    |    80 |-||
| [udf_example.cc](#udf_examplecc)                                        |  1209 | Example file of user-defined functions. ||
| [udf_example.def](#udf_exampledef)                                      |    54 |-||
| [uniques.cc](#uniquescc)                                                |   714 | Function to handle quick removal of duplicates. ||
| [uniques.h](#uniquesh)                                                  |    71 |-||
| [unireg.cc](#uniregcc)                                                  |  1344 | Create a unireg format file (`.frm`) from a `FIELD` and field-info struct. ||
| [unireg.h](#uniregh)                                                    |    26 |-||
| [xa.cc](#xacc)                                                          |  1396 |||
| [xa.h](#xah)                                                            |   729 |||
| [xa_aux.h](#xa_auxh)                                                    |    55 |||

## abstract_query_plan.cc
## abstract_query_plan.h
## add_errmsg
## aggregate_check.cc
## aggregate_check.h
## atomic_class.h
## binlog.cc
## binlog.h
## bootstrap.cc
## bootstrap.h
## bootstrap_impl.h
## bounded_queue.h
## client_settings.h
## command_service.cc
## datadict.cc
## datadict.h
## debug_sync.cc
## debug_sync.h
## derror.cc
## derror.h
## des_key_file.cc
## des_key_file.h
## discover.cc
## discover.h
## discrete_interval.h
## dynamic_ids.cc
## dynamic_ids.h
## event_data_objects.cc
## event_data_objects.h
## event_db_repository.cc
## event_db_repository.h
## event_parse_data.cc
## event_parse_data.h
## event_queue.cc
## event_queue.h
## event_scheduler.cc
## event_scheduler.h
## events.cc
## events.h
## field.cc
## field.h
## field_conv.cc
## filesort.cc
## filesort.h
## filesort_utils.cc
## filesort_utils.h
## gen_lex_hash.cc
## gen_lex_token.cc
## geometry_rtree.cc
## gis_bg_traits.h
## gstream.cc
## gstream.h
## ha_ndb_ddl_fk.cc
## ha_ndb_index_stat.cc
## ha_ndb_index_stat.h
## ha_ndbcluster.cc
## ha_ndbcluster.h
## ha_ndbcluster_binlog.cc
## ha_ndbcluster_binlog.h
## ha_ndbcluster_cond.cc
## ha_ndbcluster_cond.h
## ha_ndbcluster_connection.cc
## ha_ndbcluster_connection.h
## ha_ndbcluster_glue.h
## ha_ndbcluster_push.cc
## ha_ndbcluster_push.h
## ha_ndbcluster_tables.h
## ha_ndbinfo.cc
## ha_ndbinfo.h
## handler.cc

## handler.h

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
};
```

## hash_filo.h
## hostname.cc
## hostname.h
## init.cc
## init.h
## inplace_vector.h
## item.cc
## item.h
## item_buff.cc
## item_cmpfunc.cc
## item_cmpfunc.h
## item_create.cc
## item_create.h
## item_func.cc
## item_func.h
## item_geofunc.cc
## item_geofunc.h
## item_geofunc_buffer.cc
## item_geofunc_internal.cc
## item_geofunc_internal.h
## item_geofunc_relchecks.cc
## item_geofunc_relchecks_bgwrap.cc
## item_geofunc_relchecks_bgwrap.h
## item_geofunc_setops.cc
## item_inetfunc.cc
## item_inetfunc.h
## item_json_func.cc
## item_json_func.h
## item_row.cc
## item_row.h
## item_strfunc.cc
## item_strfunc.h
## item_subselect.cc
## item_subselect.h
## item_sum.cc
## item_sum.h
## item_timefunc.cc
## item_timefunc.h
## item_xmlfunc.cc
## item_xmlfunc.h
## json_binary.cc
## json_binary.h
## json_dom.cc
## json_dom.h
## json_path.cc
## json_path.h
## key.cc
## key.h
## keycaches.cc
## keycaches.h
## keyring_service.cc
## lex.h
## lex_symbol.h
## lock.cc
## lock.h
## locking_service.cc
## locking_service.def
## locking_service.h
## locking_service_udf.cc
## log.cc
## log.h
## log_event.cc
## log_event.h
## log_event_old.cc
## log_event_old.h
## main.cc
## malloc_allocator.h
## mdl.cc
## mdl.h
## mem_root_array.h
## memroot_allocator.h
## merge_sort.h
## message.h
## message.mc
## message.rc
## mf_iocache.cc
## migrate_keyring.cc
## migrate_keyring.h
## my_decimal.cc
## my_decimal.h
## mysqld.cc

## mysqld.h



## mysqld_daemon.cc
## mysqld_daemon.h
## mysqld_suffix.h
## mysqld_thd_manager.cc
## mysqld_thd_manager.h
## named_pipe.cc
## named_pipe.h
## ndb_anyvalue.cc
## ndb_anyvalue.h
## ndb_binlog_extra_row_info.cc
## ndb_binlog_extra_row_info.h
## ndb_binlog_thread.cc
## ndb_binlog_thread.h
## ndb_component.cc
## ndb_component.h
## ndb_conflict.cc
## ndb_conflict.h
## ndb_conflict_trans.cc
## ndb_conflict_trans.h
## ndb_dist_priv_util.h
## ndb_event_data.cc
## ndb_event_data.h
## ndb_find_files_list.cc
## ndb_find_files_list.h
## ndb_global_schema_lock.cc
## ndb_global_schema_lock.h
## ndb_global_schema_lock_guard.h
## ndb_local_connection.cc
## ndb_local_connection.h
## ndb_local_schema.cc
## ndb_local_schema.h
## ndb_log.cc
## ndb_log.h
## ndb_mi.cc
## ndb_mi.h
## ndb_name_util.cc
## ndb_name_util.h
## ndb_ndbapi_util.cc
## ndb_ndbapi_util.h
## ndb_repl_tab.cc
## ndb_repl_tab.h
## ndb_schema_dist.cc
## ndb_schema_dist.h
## ndb_schema_object.cc
## ndb_schema_object.h
## ndb_share.cc
## ndb_share.h
## ndb_table_guard.h
## ndb_tdc.cc
## ndb_tdc.h
## ndb_thd.cc
## ndb_thd.h
## ndb_thd_ndb.cc
## ndb_thd_ndb.h
## ndb_util_thread.h
## net_serv.cc
## nt_servc.cc
## nt_servc.h
## opt_costconstantcache.cc
## opt_costconstantcache.h
## opt_costconstants.cc
## opt_costconstants.h
## opt_costmodel.cc
## opt_costmodel.h
## opt_explain.cc
## opt_explain.h
## opt_explain_format.h
## opt_explain_json.cc
## opt_explain_json.h
## opt_explain_traditional.cc
## opt_explain_traditional.h
## opt_hints.cc
## opt_hints.h
## opt_range.cc
## opt_range.h
## opt_statistics.cc
## opt_statistics.h
## opt_sum.cc
## opt_trace.cc
## opt_trace.h
## opt_trace2server.cc
## opt_trace_Doxyfile
## opt_trace_context.h
## parse_file.cc
## parse_file.h
## parse_location.h
## parse_tree_helpers.cc
## parse_tree_helpers.h
## parse_tree_hints.cc
## parse_tree_hints.h
## parse_tree_items.cc
## parse_tree_items.h
## parse_tree_node_base.cc
## parse_tree_node_base.h
## parse_tree_nodes.cc
## parse_tree_nodes.h
## parser_service.cc
## partition_element.h
## partition_info.cc
## partition_info.h
## plistsort.c
## procedure.cc
## procedure.h
## protocol.h
## protocol_callback.cc
## protocol_callback.h
## protocol_classic.cc
## protocol_classic.h
## query_options.h
## records.cc
## records.h
## replication.h
## rpl_binlog_sender.cc
## rpl_binlog_sender.h
## rpl_channel_service_interface.cc
## rpl_channel_service_interface.h
## rpl_constants.h
## rpl_context.cc
## rpl_context.h
## rpl_filter.cc
## rpl_filter.h
## rpl_group_replication.cc
## rpl_group_replication.h
## rpl_gtid.h
## rpl_gtid_execution.cc
## rpl_gtid_misc.cc
## rpl_gtid_mutex_cond_array.cc
## rpl_gtid_owned.cc
## rpl_gtid_persist.cc
## rpl_gtid_persist.h
## rpl_gtid_set.cc
## rpl_gtid_sid_map.cc
## rpl_gtid_specification.cc
## rpl_gtid_state.cc
## rpl_handler.cc
## rpl_handler.h
## rpl_info.cc
## rpl_info.h
## rpl_info_dummy.cc
## rpl_info_dummy.h
## rpl_info_factory.cc
## rpl_info_factory.h
## rpl_info_file.cc
## rpl_info_file.h
## rpl_info_handler.cc
## rpl_info_handler.h
## rpl_info_table.cc
## rpl_info_table.h
## rpl_info_table_access.cc
## rpl_info_table_access.h
## rpl_info_values.cc
## rpl_info_values.h
## rpl_injector.cc
## rpl_injector.h
## rpl_master.cc
## rpl_master.h
## rpl_mi.cc
## rpl_mi.h
## rpl_msr.cc
## rpl_msr.h
## rpl_mts_submode.cc
## rpl_mts_submode.h
## rpl_record.cc
## rpl_record.h
## rpl_record_old.cc
## rpl_record_old.h
## rpl_reporting.cc
## rpl_reporting.h
## rpl_rli.cc
## rpl_rli.h
## rpl_rli_pdb.cc
## rpl_rli_pdb.h
## rpl_slave.cc
## rpl_slave.h
## rpl_slave_commit_order_manager.cc
## rpl_slave_commit_order_manager.h
## rpl_table_access.cc
## rpl_table_access.h
## rpl_tblmap.cc
## rpl_tblmap.h
## rpl_transaction_ctx.cc
## rpl_transaction_ctx.h
## rpl_transaction_write_set_ctx.cc
## rpl_transaction_write_set_ctx.h
## rpl_trx_boundary_parser.cc
## rpl_trx_boundary_parser.h
## rpl_trx_tracking.cc
## rpl_trx_tracking.h
## rpl_utility.cc
## rpl_utility.h
## rpl_write_set_handler.cc
## rpl_write_set_handler.h
## rules_table_service.cc
## select_lex_visitor.cc
## select_lex_visitor.h
## session_tracker.cc
## session_tracker.h
## set_var.cc
## set_var.h
## signal_handler.cc
## sp.cc
## sp.h
## sp_cache.cc
## sp_cache.h
## sp_head.cc
## sp_head.h
## sp_instr.cc
## sp_instr.h
## sp_pcontext.cc
## sp_pcontext.h
## sp_rcontext.cc
## sp_rcontext.h
## spatial.cc
## spatial.h
## sql_admin.cc
## sql_admin.h
## sql_alloc.h
## sql_alloc_error_handler.cc
## sql_alter.cc
## sql_alter.h
## sql_alter_instance.cc
## sql_alter_instance.h
## sql_analyse.cc
## sql_analyse.h
## sql_array.h
## sql_audit.cc
## sql_audit.h
## sql_base.cc
## sql_base.h
## sql_binlog.cc
## sql_binlog.h
## sql_bitmap.h
## sql_bootstrap.cc
## sql_bootstrap.h
## sql_builtin.cc.in
## sql_cache.cc
## sql_cache.h
## sql_callback.h
## sql_class.cc
## sql_class.h
## sql_client.cc
## sql_cmd.h
## sql_cmd_dml.h
## sql_connect.cc
## sql_connect.h
## sql_const.h
## sql_crypt.cc
## sql_crypt.h
## sql_cursor.cc
## sql_cursor.h
## sql_data_change.cc
## sql_data_change.h
## sql_db.cc
## sql_db.h
## sql_delete.cc
## sql_delete.h
## sql_derived.cc
## sql_derived.h
## sql_digest.cc
## sql_digest.h
## sql_digest_stream.h
## sql_do.cc
## sql_do.h
## sql_error.cc
## sql_error.h
## sql_exception_handler.cc
## sql_exception_handler.h
## sql_executor.cc
## sql_executor.h
## sql_get_diagnostics.cc
## sql_get_diagnostics.h
## sql_handler.cc
## sql_handler.h
## sql_help.cc
## sql_help.h
## sql_hints.yy
## sql_hset.h
## sql_initialize.cc
## sql_initialize.h
## sql_insert.cc
## sql_insert.h
## sql_join_buffer.cc
## sql_join_buffer.h
## sql_lex.cc
## sql_lex.h
## sql_lex_hash.cc
## sql_lex_hash.h
## sql_lex_hints.cc
## sql_lex_hints.h
## sql_list.cc
## sql_list.h
## sql_load.cc
## sql_load.h
## sql_locale.cc
## sql_locale.h
## sql_manager.cc
## sql_manager.h
## sql_opt_exec_shared.h
## sql_optimizer.cc
## sql_optimizer.h
## sql_parse.cc
## sql_parse.h
## sql_partition.cc
## sql_partition.h
## sql_partition_admin.cc
## sql_partition_admin.h
## sql_planner.cc
## sql_planner.h
## sql_plist.h
## sql_plugin.cc
## sql_plugin.h
## sql_plugin_enum.h
## sql_plugin_ref.h
## sql_plugin_services.h
## sql_prepare.cc
## sql_prepare.h
## sql_profile.cc
## sql_profile.h
## sql_query_rewrite.cc
## sql_query_rewrite.h
## sql_reload.cc
## sql_reload.h
## sql_rename.cc
## sql_rename.h
## sql_resolver.cc
## sql_resolver.h
## sql_rewrite.cc
## sql_rewrite.h
## sql_select.cc
## sql_select.h
## sql_servers.cc
## sql_servers.h
## sql_show.cc
## sql_show.h
## sql_show_status.cc
## sql_show_status.h
## sql_signal.cc
## sql_signal.h
## sql_sort.h
## sql_state.c
## sql_table.cc
## sql_table.h
## sql_tablespace.cc
## sql_tablespace.h
## sql_test.cc
## sql_test.h
## sql_thd_internal_api.cc
## sql_thd_internal_api.h
## sql_time.cc
## sql_time.h
## sql_timer.cc
## sql_timer.h
## sql_tmp_table.cc
## sql_tmp_table.h
## sql_trigger.cc
## sql_trigger.h
## sql_truncate.cc
## sql_truncate.h
## sql_udf.cc
## sql_udf.h
## sql_union.cc
## sql_union.h
## sql_update.cc
## sql_update.h
## sql_view.cc
## sql_view.h
## sql_yacc.yy
## srv_session.cc
## srv_session.h
## srv_session_info_service.cc
## srv_session_service.cc
## ssl_wrapper_service.cc
## strfunc.cc
## strfunc.h
## string_service.cc
## string_service.h
## sys_vars.cc
## sys_vars.h
## sys_vars_resource_mgr.cc
## sys_vars_resource_mgr.h
## sys_vars_shared.h
## table.cc
## table.h
## table_cache.cc
## table_cache.h
## table_trigger_dispatcher.cc
## table_trigger_dispatcher.h
## table_trigger_field_support.h
## tc_log.cc
## tc_log.h
## tempCodeRunnerFile.cc
## thr_malloc.cc
## thr_malloc.h
## transaction.cc
## transaction.h
## transaction_info.cc
## transaction_info.h
## trigger.cc
## trigger.h
## trigger_chain.cc
## trigger_chain.h
## trigger_creation_ctx.cc
## trigger_creation_ctx.h
## trigger_def.h
## trigger_loader.cc
## trigger_loader.h
## tzfile.h
## tztime.cc
## tztime.h
## udf_example.cc
## udf_example.def
## uniques.cc
## uniques.h
## unireg.cc
## unireg.h
## xa.cc
## xa.h
## xa_aux.h
