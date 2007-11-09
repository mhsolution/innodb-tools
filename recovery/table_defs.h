#ifndef table_defs_h
#define table_defs_h

// Table definitions
table_def_t table_definitions[] = {
	{
		name: "company_track",
		{
			{ /*  */
				name: "DB_ROW_ID",
				type: FT_INTERNAL,
				fixed_length: 6,

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
			{ /* mediumint(9) */
				name: "User_Id",
				type: FT_INT,
				fixed_length: 3,

				has_limits: TRUE,
				limits: {
					int_min_val: 0,
					int_max_val: 32000
				},

				can_be_null: FALSE
			},
			{ /* text */
				name: "Company",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* mediumint(9) */
				name: "Company_No",
				type: FT_INT,
				fixed_length: 3,

				has_limits: TRUE,
				limits: {
					int_min_val: 0,
					int_max_val: 30000,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* text */
				name: "Sector",
				type: FT_TEXT,
				min_length: 0,
				max_length: 65535,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 65535,
					char_ascii_only: TRUE
				},

				can_be_null: TRUE
			},
			{ /* datetime */
				name: "Timestamp",
				type: FT_DATETIME,
				fixed_length: 8,

				can_be_null: TRUE
			},
			{ type: FT_NONE }
		}
	},
	{
		name: "users",
		{
			{ /* mediumint(9) */
				name: "User_Id",
				type: FT_INT,
				fixed_length: 3,

				has_limits: TRUE,
				limits: {
					int_min_val: 1,
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
			{ /* tinytext */
				name: "Username",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 2,
					char_max_len: 30,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Password",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 2,
					char_max_len: 50,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* date */
				name: "Last_Login",
				type: FT_DATE,
				fixed_length: 8,

				can_be_null: TRUE
			},
			{ /* mediumint(9) */
				name: "Num_Logins",
				type: FT_INT,
				fixed_length: 3,

				has_limits: TRUE,
				limits: {
					int_min_val: 0,
					int_max_val: 10000,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Title",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "First_Name",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 50,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Surname",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 50,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Job_Title",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 150,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Company",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 155,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Email",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Country",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 50,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Stakeholder_Group",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 50,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Other_Stakeholder",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 100,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Sector_Involvement",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 50,
					char_ascii_only: TRUE,
					can_be_null: FALSE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Address_1",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Address_2",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Address_3",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Town_City",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Post_Code",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Telephone",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "Third_Parties",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* tinytext */
				name: "IP_Address",
				type: FT_TEXT,
				min_length: 0,
				max_length: 255,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 255,
					char_ascii_only: TRUE,
					can_be_null: TRUE
				},

				can_be_null: TRUE
			},
			{ /* date */
				name: "Reg_Date",
				type: FT_DATE,
				fixed_length: 8,

				can_be_null: TRUE
			},
			{ /* date */
				name: "Updated_Date",
				type: FT_DATE,
				fixed_length: 8,

				can_be_null: TRUE
			},
			{ /* tinyint(4) */
				name: "Suspended",
				type: FT_INT,
				fixed_length: 1,

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
};

int table_definitions_cnt = sizeof(table_definitions) / sizeof(table_def_t);



#endif
