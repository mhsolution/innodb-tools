#ifndef table_defs_h
#define table_defs_h

// Table definitions
table_def_t table_definitions[] = {
	{
		name: "tj",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* enum('yes','no') */
				name: "auto_restart",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "total_tax",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_dealt_today",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time_yesterday",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time_today",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "subscription_launch_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "profit_matrix_backup_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sidebet_jackpot",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_admin_actions",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "player_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "admin_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* enum('rename','enable','disable') */
				name: "action",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 3,
					enum_values: { "rename", "enable", "disable" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "from_username",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "to_username",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_admins",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "player_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "affiliate_admin",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "prize_admin",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "stats_admin",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "note",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_affiliate_clicks",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "affiliate_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "impressions",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "clicks",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "month",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "day",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "year",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_affiliate_globals",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* float */
				name: "def_commission",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "def_commission_2nd_tier",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "check_fee",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "check_threshold",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_affiliates",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "player_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "creation_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "master",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "master_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "name",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(100) */
				name: "fname",
				type: FT_CHAR,
				min_length: 0,
				max_length: 100,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(100) */
				name: "lname",
				type: FT_CHAR,
				min_length: 0,
				max_length: 100,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* float */
				name: "commission",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "commission_2nd_tier",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "payment_verified",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* enum('mail','paypal') */
				name: "payment_type",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "mail", "paypal" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "payment_email",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(100) */
				name: "address",
				type: FT_CHAR,
				min_length: 0,
				max_length: 100,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(100) */
				name: "address2",
				type: FT_CHAR,
				min_length: 0,
				max_length: 100,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(30) */
				name: "city",
				type: FT_CHAR,
				min_length: 0,
				max_length: 30,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 30,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "state",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(10) */
				name: "zip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 10,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 10,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "country",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "last_referrer",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "lounge_buyin_min_index",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "lounge_buyin_max_index",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('all','pp') */
				name: "lounge_player_type",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "all", "pp" }
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_auto_mtts",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* tinyint(1) */
				name: "active",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "modify_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "time_hour",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "time_min",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "portal_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "num_left",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "freq",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('hours','days','weeks','months') */
				name: "freq_units",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 4,
					enum_values: { "hours", "days", "weeks", "months" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "name",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "ticket_to_win",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "prize_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* enum('pp','all') */
				name: "eligibility",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "pp", "all" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "num_tickets_required",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "ticket_required",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "next_start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "pp_required",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "min_players",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('texas','omaha') */
				name: "type",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "texas", "omaha" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "seats",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "buyin_index",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "delay_index",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "info_url",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "info_text",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_ban",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* varchar(100) */
				name: "cookie",
				type: FT_CHAR,
				min_length: 0,
				max_length: 100,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(25) */
				name: "ip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 25,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 25,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "cid",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "note",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "update_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "updated_by",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_cached_data",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* bigint(20) */
				name: "time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "css_id",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "link_target",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "url_addition",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "text",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_daily_stats",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* bigint(20) */
				name: "startup_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "day_length",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "num_active_players",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* double */
				name: "avg_hands_per_player",
				type: FT_DOUBLE,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* double */
				name: "avg_players_per_hand",
				type: FT_DOUBLE,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_dealt",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_fail_msgs",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "title",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "msg",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_fb_invites",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* bigint(20) */
				name: "from_id",
				type: FT_INT,
				fixed_length: 8,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "to_id",
				type: FT_INT,
				fixed_length: 8,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* tinyint(4) */
				name: "accepted",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* tinyint(4) */
				name: "bonus_pending",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_fbml_pending",
		{
			{ /* bigint(20) */
				name: "id",
				type: FT_INT,
				fixed_length: 8,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* bigint(20) */
				name: "fb_user_id",
				type: FT_INT,
				fixed_length: 8,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_friends",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "player_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "friend_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "mutual",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_highscores",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* bigint(20) */
				name: "time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "player_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "username",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* float */
				name: "score",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_login_attempts",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* varchar(20) */
				name: "ip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "lock_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "num_failures",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* text */
				name: "logins",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_mtt_tickets",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "player_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "mtt_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "ticket",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_networks",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* varchar(60) */
				name: "name",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "secret",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_news",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* timestamp */
				name: "time",
				type: FT_UINT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "title",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "msg",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_num_hand_players",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "num_players",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_players",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* enum('yes','no') */
				name: "verified",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "enabled",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "admin",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "stealth_admin",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "hidden",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "randcode",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "username",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(35) */
				name: "password_hash",
				type: FT_CHAR,
				min_length: 0,
				max_length: 35,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 35,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "network_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "network_userid",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* varchar(30) */
				name: "network_username",
				type: FT_CHAR,
				min_length: 0,
				max_length: 30,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 30,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(35) */
				name: "network_password",
				type: FT_CHAR,
				min_length: 0,
				max_length: 35,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 35,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "signup_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(35) */
				name: "cookie",
				type: FT_CHAR,
				min_length: 0,
				max_length: 35,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 35,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(35) */
				name: "cid",
				type: FT_CHAR,
				min_length: 0,
				max_length: 35,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 35,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(16) */
				name: "referrer",
				type: FT_CHAR,
				min_length: 0,
				max_length: 16,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 16,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "aff_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "user_agent",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "platform",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "plugin_version",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "email",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "pending_email",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_paypal_active",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_paypal_trial_end_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_paypal_period_start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sub_paypal_months",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_cnb_active",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_cnb_trial_end_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_cnb_term_pending",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_cnb_recur_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_cnb_def_id",
				type: FT_INT,
				fixed_length: 8,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_cnb_period_start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sub_cnb_months",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_trial_started",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sub_months",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sub_days",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_manual_end_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_lifetime",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "donation_expire_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "donation",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "score",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "raw_score",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "raw_score_diff",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "total_profit",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips_saved",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "buyins",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_buyin",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_lobby_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_hand_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_tax_hand",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_reset",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(18) */
				name: "last_ip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 18,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 18,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "last_port",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* text */
				name: "ip_list",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "cookie_list",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "cid_list",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "max_tax",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "total_tax",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_played",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_played_today",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_played_yesterday",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_played_today_vip",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "triplejacks",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* text */
				name: "mph",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "mph_profit",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "besthand",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "besthand_rank",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "besthand_kc",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "besthand_kc_int",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "besthand_omaha",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "besthand_omaha_rank",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "besthand_omaha_kc",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "besthand_omaha_kc_int",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* float */
				name: "best_chip_ratio",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('regular','url') */
				name: "pokerface_type",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "regular", "url" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "pokerface_url",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "pokerface",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "pokerface_rgb",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "pokerface_var",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* tinyint(4) */
				name: "flag",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "mood",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "graphics_level",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "quality_level",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sound",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "adv_auto",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "show_lobby_players",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "link_medal",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "link_url",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sidebets",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sidebets_won",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sidebets_net",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "mute_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "suspend_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "portal_auto_join_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "news_processed",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "news_initially_checked",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "custom_lobby_msg",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "fb_invites_total",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "fb_invites_accepted",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "bonus_chips_to_add",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "bonus_chips_added",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* text */
				name: "notes",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_players_041907",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* enum('yes','no') */
				name: "verified",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "enabled",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "admin",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "stealth_admin",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "hidden",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "randcode",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "username",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(35) */
				name: "password_hash",
				type: FT_CHAR,
				min_length: 0,
				max_length: 35,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 35,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "signup_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(35) */
				name: "cookie",
				type: FT_CHAR,
				min_length: 0,
				max_length: 35,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 35,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(35) */
				name: "cid",
				type: FT_CHAR,
				min_length: 0,
				max_length: 35,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 35,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(16) */
				name: "referrer",
				type: FT_CHAR,
				min_length: 0,
				max_length: 16,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 16,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "aff_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "user_agent",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "platform",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "plugin_version",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "email",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "pending_email",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_paypal_active",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_paypal_trial_end_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_paypal_period_start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sub_paypal_months",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_cnb_active",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_cnb_trial_end_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_cnb_term_pending",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_cnb_recur_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_cnb_def_id",
				type: FT_INT,
				fixed_length: 8,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_cnb_period_start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sub_cnb_months",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_trial_started",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sub_months",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sub_days",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "sub_manual_end_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "sub_lifetime",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "donation_expire_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "donation",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "score",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "raw_score",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "raw_score_diff",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "total_profit",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips_saved",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "buyins",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_buyin",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_lobby_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_hand_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_tax_hand",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "last_reset",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(18) */
				name: "last_ip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 18,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 18,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "last_port",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* text */
				name: "ip_list",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "cookie_list",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "cid_list",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "max_tax",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "total_tax",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_played",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_played_today",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_played_yesterday",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands_played_today_vip",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "triplejacks",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* text */
				name: "mph",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "mph_profit",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "besthand",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "besthand_rank",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "besthand_kc",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "besthand_kc_int",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "besthand_omaha",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "besthand_omaha_rank",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "besthand_omaha_kc",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "besthand_omaha_kc_int",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* float */
				name: "best_chip_ratio",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "pokerface",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "pokerface_rgb",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "pokerface_var",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* tinyint(4) */
				name: "flag",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "mood",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "graphics_level",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "quality_level",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sound",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "adv_auto",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "show_lobby_players",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "link_medal",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "link_url",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sidebets",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sidebets_won",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "sidebets_net",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "mute_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "suspend_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "portal_auto_join_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "news_processed",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* enum('yes','no') */
				name: "news_initially_checked",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "yes", "no" }
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "custom_lobby_msg",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "notes",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_prices",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* tinyint(1) */
				name: "active",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "months",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "price",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "trial_length",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('D','W','M','Y') */
				name: "trial_units",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 4,
					enum_values: { "D", "W", "M", "Y" }
				},

				can_be_null: FALSE
			},
			{ /* float */
				name: "trial_price",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_prizes",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* tinyint(1) */
				name: "active",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "creation_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "title",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "sdesc",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "ldesc",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* enum('pp','all') */
				name: "eligibility",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "pp", "all" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "image_url",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "sponsor_label",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "sponsor_image_url",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "sponsor_url",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "type_text",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "freq_text",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* float */
				name: "altprize_value",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "altprize_title",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* enum('hand','tourney') */
				name: "type",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "hand", "tourney" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "type_hand_rank",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "type_hand_card1",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "type_hand_card2",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('spades','hearts','diamonds','clubs','any') */
				name: "type_hand_suit",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 5,
					enum_values: { "spades", "hearts", "diamonds", "clubs", "any" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "type_hand_quantity",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "type_hand_start_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "type_hand_start_hour",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "type_hand_start_min",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "type_hand_end_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "type_tourney_freq",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* enum('hours','days','weeks') */
				name: "type_tourney_freq_units",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 3,
					enum_values: { "hours", "days", "weeks" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "type_tourney_start_hours",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "type_tourney_start_mins",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_prizes_won",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "player_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "prize_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "title",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "alt_title",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* enum('main','alt','none') */
				name: "prize_selected",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 3,
					enum_values: { "main", "alt", "none" }
				},

				can_be_null: FALSE
			},
			{ /* float */
				name: "altprize_value",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "type_text",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* tinyint(1) */
				name: "claimed",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time_won",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time_claimed",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time_complete",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* enum('usps','ups','fedex','none') */
				name: "carrier",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 4,
					enum_values: { "usps", "ups", "fedex", "none" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "tracking_number",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "tracking_url",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(50) */
				name: "lounge_name",
				type: FT_CHAR,
				min_length: 0,
				max_length: 50,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 50,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "table_name",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* enum('hand','tourney') */
				name: "type",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "hand", "tourney" }
				},

				can_be_null: FALSE
			},
			{ /* enum('unclaimed','pending','complete') */
				name: "status",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 3,
					enum_values: { "unclaimed", "pending", "complete" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(100) */
				name: "fname",
				type: FT_CHAR,
				min_length: 0,
				max_length: 100,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(100) */
				name: "lname",
				type: FT_CHAR,
				min_length: 0,
				max_length: 100,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(100) */
				name: "address",
				type: FT_CHAR,
				min_length: 0,
				max_length: 100,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(100) */
				name: "address2",
				type: FT_CHAR,
				min_length: 0,
				max_length: 100,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(30) */
				name: "city",
				type: FT_CHAR,
				min_length: 0,
				max_length: 30,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 30,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "state",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(10) */
				name: "zip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 10,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 10,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "country",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(60) */
				name: "payment_email",
				type: FT_CHAR,
				min_length: 0,
				max_length: 60,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 60,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "email",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_1",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_10",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_11",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_12",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_13",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_14",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_15",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_16",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_17",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_18",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_19",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_2",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_20",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_21",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_22",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_23",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_24",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_25",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_26",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_27",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_28",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_29",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_3",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_30",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_4",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_5",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_6",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_7",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_8",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_9",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "winner_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "loser_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "chips",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hands",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_profit_times",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "table_num",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "day_start",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "day_end",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_referrers",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* varchar(16) */
				name: "referrer",
				type: FT_CHAR,
				min_length: 0,
				max_length: 16,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 16,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "clicks",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "registrations",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "subscriptions",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_royals",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "player_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* enum('s','d','c','h','unknown') */
				name: "suit",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 5,
					enum_values: { "s", "d", "c", "h", "unknown" }
				},

				can_be_null: FALSE
			},
			{ /* enum('texas','omaha') */
				name: "game_type",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "texas", "omaha" }
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "hard",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_sessions",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* varchar(20) */
				name: "ip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* varchar(8) */
				name: "code",
				type: FT_CHAR,
				min_length: 0,
				max_length: 8,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 8,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(50) */
				name: "login",
				type: FT_CHAR,
				min_length: 0,
				max_length: 50,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 50,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(20) */
				name: "guest",
				type: FT_CHAR,
				min_length: 0,
				max_length: 20,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 20,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(50) */
				name: "affcode",
				type: FT_CHAR,
				min_length: 0,
				max_length: 50,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 50,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_skin_assets",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "skin_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* varchar(80) */
				name: "name",
				type: FT_CHAR,
				min_length: 0,
				max_length: 80,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 80,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* enum('url','color') */
				name: "type",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "url", "color" }
				},

				can_be_null: FALSE
			},
			{ /* varchar(255) */
				name: "val",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "offset_x",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "offset_y",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_skins",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
				name: "name",
				type: FT_CHAR,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_suspend",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* varchar(18) */
				name: "ip",
				type: FT_CHAR,
				min_length: 0,
				max_length: 18,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 18,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* varchar(40) */
				name: "cid",
				type: FT_CHAR,
				min_length: 0,
				max_length: 40,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 40,
					char_ascii_only: TRUE
				},

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "suspend_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "tj_tax",
		{
			{ /* int(11) */
				name: "id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
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
			{ /* bigint(20) */
				name: "tax_time",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* bigint(20) */
				name: "time_since_last",
				type: FT_INT,
				fixed_length: 8,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "player_id",
				type: FT_INT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					int_min_val: -30000,
					int_max_val: 30000
				},

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "tax_amount",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* int(11) */
				name: "full_tax_amount",
				type: FT_INT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "tax_perc",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "chips_perc",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ /* float */
				name: "score_change",
				type: FT_FLOAT,
				fixed_length: 4,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
};

int table_definitions_cnt = sizeof(table_definitions) / sizeof(table_def_t);



#endif
