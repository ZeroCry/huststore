/* See items.c */

/*@null@*/
item *do_item_alloc ( char *key, const size_t nkey, const int flags, const rel_time_t exptime, char *value, const int nbytes, const uint32_t cur_hv );
void item_free ( item *it );
bool item_size_ok ( const size_t nkey, const int flags, const int nbytes );

int do_item_link ( item *it, const uint32_t hv ); /** may fail if transgresses limits */
void do_item_unlink ( item *it, const uint32_t hv );
void do_item_unlink_nolock ( item *it, const uint32_t hv );
void do_item_remove ( item *it );
void do_item_update ( item *it ); /** update LRU time to current and reposition */
void do_item_update_nolock ( item *it );
int do_item_replace ( item *it, item *new_it, const uint32_t hv );

item *do_item_get ( const char *key, const size_t nkey, const uint32_t hv );
item *do_item_touch ( const char *key, const size_t nkey, uint32_t exptime, const uint32_t hv );
extern pthread_mutex_t lru_locks[POWER_LARGEST];
void item_stats_evictions ( uint64_t *evicted );

enum crawler_result_type
{
    CRAWLER_OK = 0, CRAWLER_RUNNING, CRAWLER_BADCLASS, CRAWLER_NOTSTARTED
};

int start_lru_maintainer_thread ( void );
int stop_lru_maintainer_thread ( void );
int init_lru_maintainer ( void );
void lru_maintainer_pause ( void );
void lru_maintainer_resume ( void );

int start_item_crawler_thread ( void );
int stop_item_crawler_thread ( void );
int init_lru_crawler ( void );
enum crawler_result_type lru_crawler_crawl ( char *slabs );
void lru_crawler_pause ( void );
void lru_crawler_resume ( void );
