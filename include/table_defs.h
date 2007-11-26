#ifndef table_defs_h
#define table_defs_h

// Table definitions
table_def_t table_definitions[] = {
	{
		name: "reptest",
		{
			{ /* int(10) unsigned */
				name: "id",
				type: FT_UINT,
				fixed_length: 4,

				has_limits: TRUE,
				limits: {
					uint_min_val: 0,
					uint_max_val: 30000
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
			{ /* varchar(32) */
				name: "a",
				type: FT_CHAR,
				min_length: 0,
				max_length: 32,

				has_limits: TRUE,
				limits: {
					char_min_len: 0,
					char_max_len: 32,
					char_ascii_only: TRUE
				},

				can_be_null: TRUE
			},
			{ /* enum('odd','even') */
				name: "b",
				type: FT_ENUM,
				fixed_length: 1,

				has_limits: TRUE,
				limits: {
					enum_values_count: 2,
					enum_values: { "odd", "even" }
				},

				can_be_null: FALSE
			},
			{ type: FT_NONE }
		}
	},
};

#endif
