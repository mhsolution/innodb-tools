#ifndef table_defs_h
#define table_defs_h

// Table definitions
table_def_t table_definitions[] = {
	{
		name: "account_details",
		{
			{ /* int(11) */
				name: "details_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 10000
				}
			},
			{ /*  */
				name: "DB_TRX_ID",
				type: FT_INTERNAL,
				fixed_length: 6,
				can_be_null: FALSE
			},
			{ /*  */
				name: "DB_ROLL_PTR",
				type: FT_INTERNAL,
				fixed_length: 7,
				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "client_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 10000
				}
			},
			{ /* int(11) */
				name: "cp_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 10000
				}
			},
			{ /* int(11) */
				name: "domain_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: TRUE,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 10000
				}
			},
			{ /* varchar(255) */
				name: "ip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: TRUE
			},
			{ /* varchar(255) */
				name: "server",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "server_type",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 0,
					int_max_val: 100
				}
			},
			{ /* varchar(255) */
				name: "username",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "password",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: TRUE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "client_package",
		{
			{ /* 0 - int(11) */
				name: "cp_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 2500
				}
			},
			{ /* 1 */
				name: "DB_TRX_ID",
				type: FT_INTERNAL,
				fixed_length: 6,
				can_be_null: FALSE
			},
			{ /* 2 */
				name: "DB_ROLL_PTR",
				type: FT_INTERNAL,
				fixed_length: 7,
				can_be_null: FALSE
			},
			{ /* 3 - int(11) */
				name: "client_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 500
				}
			},
			{ /* 4 - int(11) */
				name: "pack_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 2500
				}
			},
			{ /* 5 - varchar(11) */
				name: "pack_price",
				type: FT_CHAR,
				min_length: 0,
				max_length: 11,
				can_be_null: FALSE,
				
				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 10,
					char_ascii_only: TRUE
				}
			},
			{ /* 6 - int(11) */
				name: "parent_cp_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: TRUE,

				has_limits: TRUE,
				limits: {
					int_min_val: 0,
					int_max_val: 2500
				}
			},
			{ /* 7 - int(11) */
				name: "cp_qty",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 200
				}
			},
			{ /* 8 - decimal(5,2) */
				name: "cp_discount",
				type: FT_CHAR,
				min_length: 0,
				max_length: 25,
				can_be_null: FALSE
			},
			{ /* 9 - int(11) */
				name: "cp_start_stamp",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE
			},
			{ /* 10 - int(11) */
				name: "cp_renew_stamp",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE
			},
			{ /* 11 - varchar(25) */
				name: "cp_billing_cycle",
				type: FT_CHAR,
				min_length: 0,
				max_length: 25,
				can_be_null: FALSE
			},
			{ /* 12 - varchar(25) */
				name: "cp_status",
				type: FT_CHAR,
				min_length: 0,
				max_length: 25,
				can_be_null: FALSE
			},
			{ /* 13 - mediumtext */
				name: "cp_comments",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65000,
				can_be_null: TRUE
			},
			{ /* 14 - int(11) */
				name: "cp_renewed_on",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE
			},
			{ /* 15 - int(11) */
				name: "cp_stamp",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE
			},
			{ /* 16 - varchar(255) */
				name: "aff_code",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: TRUE
			},
			{ /* 17 - int(11) */
				name: "aff_last_paid",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: TRUE
			},
			{ /* 18 - varchar(255) */
				name: "domain",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: TRUE,
				
				has_limits: FALSE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				}
			},
			{ /* 19 - varchar(255) */
				name: "ip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: TRUE,
				
				has_limits: FALSE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				}
			},
			{ /* 20 - varchar(255) */
				name: "server",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: TRUE
			},
			{ /* 21 - varchar(255) */
				name: "username",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: TRUE,
				
				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				}
			},
			{ /* 22 - varchar(255) */
				name: "password",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: TRUE,
				
				has_limits: FALSE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				}
			},
			{ /* 23 - varchar(255) */
				name: "external_id",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: TRUE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "domain_names",
		{
			{ /* int(11) */
				name: "domain_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 2500
				}
			},
			{ /*  */
				name: "DB_TRX_ID",
				type: FT_INTERNAL,
				fixed_length: 6,
				can_be_null: FALSE
			},
			{ /*  */
				name: "DB_ROLL_PTR",
				type: FT_INTERNAL,
				fixed_length: 7,
				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "domain_name",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,
				can_be_null: FALSE,
				
				has_limits: TRUE,
				limits: {
					char_min_len: 4,
					char_max_len: 100,
					char_ascii_only: TRUE
				}
			},
			{ /* int(11) */
				name: "client_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,
				
				has_limits: TRUE,
				limits: {
					int_min_val: 1,
					int_max_val: 500
				}
			},
			{ /* int(11) */
				name: "domain_created",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 0, // Jan, 1, 1970
					int_max_val: 1577854800 // Jan, 1, 2020
				}
			},
			{ /* int(11) */
				name: "domain_expires",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 0, // Jan, 1, 1970
					int_max_val: 1577854800 // Jan, 1, 2020
				}
			},
			{ /* int(11) */
				name: "registrar_id",
				type: FT_INT,
				fixed_length: 4,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 0,
					int_max_val: 10000
				}
			},
			{ /* tinyint(3) */
				name: "monitor",
				type: FT_INT,
				fixed_length: 1,
				can_be_null: FALSE,

				has_limits: TRUE,
				limits: {
					int_min_val: 0,
					int_max_val: 10000
				}
			},
			{ type: FT_NONE }
		}
	},
};

int table_definitions_cnt = sizeof(table_definitions) / sizeof(table_def_t);



#endif
