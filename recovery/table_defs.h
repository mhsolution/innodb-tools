// Table definitions
table_def_t table_definitions[] = {
/*
	{ 
		"test_int", 	// name
		3, 				// fields count
		4+6+7, 			// min data size
		4+6+7,			// max_data_size
		{				// fields array
			{ "id", FT_UINT, 4, 4, TRUE, 0, 100000 },
			{ "_idb2", FT_INTERNAL, 6, 6, FALSE, 0, 0},
			{ "_idb3", FT_INTERNAL, 7, 7, FALSE, 0, 0}
		}
	},
	
	{ 
		"test_string", 
		3+1, 
		6+6+7+32, 
		6+6+7+32,
		{
			{ "_idb1", FT_INTERNAL, 6, 6, FALSE, 0, 0},
			{ "_idb2", FT_INTERNAL, 6, 6, FALSE, 0, 0},
			{ "_idb3", FT_INTERNAL, 7, 7, FALSE, 0, 0},
			{ "id", FT_CHAR, 32, 32, FALSE, 0, 0}
		}
	},
	
	{ 
		"test_string2", 
		3+2, 
		6+6+7+10+5, 
		6+6+7+10+5,
		{
			{ "_idb1", FT_INTERNAL, 6, 6, FALSE, 0, 0},
			{ "_idb2", FT_INTERNAL, 6, 6, FALSE, 0, 0},
			{ "_idb3", FT_INTERNAL, 7, 7, FALSE, 0, 0},
			{ "a", FT_CHAR, 10, 10, FALSE, 0, 0},
    		{ "b", FT_CHAR, 5, 5, FALSE, 0, 0}
		}
	},
*/
	{
		"filter_request_work_logs",
		{
			{ "filter_request_work_log_id", FT_UINT, 8, 8 },
			{ "_idb2", FT_INTERNAL, 6, 6 },
			{ "_idb3", FT_INTERNAL, 7, 7 },
			{ "author", FT_CHAR, 0, 8 },
			{ "filter_request_id", FT_UINT, 8, 8 },
			{ "log", FT_CHAR, 0, 100 },
			{ "log_at", FT_DATETIME, 0, 8 },
			{ "", 0 }
		}
	},
	
	{
		"filter_patterns", 
		{
			{ "filter_pattern_id", FT_UINT, 8, 8 },
			{ "_idb2", FT_INTERNAL, 6, 6 },
			{ "_idb3", FT_INTERNAL, 7, 7 },
			{ "pattern_type", FT_UINT, 1, 1 },
			{ "pattern", FT_CHAR, 0, 1000 },
			{ "filter_request_id", FT_UINT, 8, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 1, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "negation", FT_INT, 1, 1 },
			{ "", 0 }
		}
	}
};

int table_definitions_cnt = sizeof(table_definitions) / sizeof(table_def_t);
