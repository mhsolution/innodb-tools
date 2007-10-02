#ifndef table_defs_h
#define table_defs_h

// Table definitions
table_def_t table_definitions[] = {
	{
		"announcements",
		{
			{ "announcement_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "text", FT_CHAR, 0, 65535 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "effective_on", FT_DATETIME, 8, 8 },
			{ "effective_til", FT_DATETIME, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"application_instances",
		{
			{ "application_instance_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "name", FT_CHAR, 0, 255 },
			{ "status", FT_UINT, 1, 1 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"associated_softwares",
		{
			{ "associated_software_id", FT_UINT, 4, 4 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "name", FT_CHAR, 0, 50 },
			{ "description", FT_CHAR, 0, 50 },
			{ "owner", FT_CHAR, 0, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "overseer", FT_CHAR, 0, 8 },
			{ "status", FT_UINT, 1, 1 },
			{ "", 0 }
		}
	},
	{
		"attributes",
		{
			{ "attribute_id", FT_INT, 1, 1 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "name", FT_CHAR, 0, 65535 },
			{ "platform", FT_CHAR, 0, 25 },
			{ "", 0 }
		}
	},
	{
		"build_candidates",
		{
			{ "build_candidate_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "test_plan", FT_CHAR, 0, 65535 },
			{ "test_result_detail", FT_CHAR, 0, 65535 },
			{ "assigned_qa", FT_CHAR, 0, 8 },
			{ "builder", FT_CHAR, 0, 8 },
			{ "status", FT_UINT, 1, 1 },
			{ "software_change_id", FT_UINT, 8, 8 },
			{ "associated_software_id", FT_UINT, 4, 4 },
			{ "approver", FT_CHAR, 0, 8 },
			{ "approval_datetime", FT_DATETIME, 0, 8 },
			{ "test_result", FT_INT, 0, 1 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "title", FT_CHAR, 0, 200 },
			{ "", 0 }
		}
	},
	{
		"build_units",
		{
			{ "build_unit_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "build_candidate_id", FT_UINT, 8, 8 },
			{ "developer", FT_CHAR, 0, 8 },
			{ "version_control_type_id", FT_UINT, 1, 1 },
			{ "vc_reference", FT_CHAR, 0, 100 },
			{ "code_reviewer", FT_CHAR, 0, 8 },
			{ "review_date", FT_DATETIME, 0, 8 },
			{ "initial_summit_date", FT_DATETIME, 8, 8 },
			{ "short_description", FT_CHAR, 0, 255 },
			{ "long_description", FT_CHAR, 0, 65535 },
			{ "associated_software_id", FT_UINT, 4, 4 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"change_detect_config_reviews",
		{
			{ "change_detect_config_review_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "change_detect_config_name", FT_CHAR, 0, 255 },
			{ "reviewed_by", FT_CHAR, 0, 8 },
			{ "reviewed_date", FT_DATETIME, 0, 8 },
			{ "reviewed_change_detect_config_id", FT_UINT, 0, 8 },
			{ "start_date", FT_DATETIME, 8, 8 },
			{ "", 0 }
		}
	},
	{
		"change_detect_config_rules",
		{
			{ "change_detect_config_rule_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "change_detect_config_id", FT_UINT, 8, 8 },
			{ "software_identifier_type_id", FT_UINT, 1, 1 },
			{ "software_identifier", FT_CHAR, 0, 65535 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "release_mgmt_system_id", FT_UINT, 1, 1 },
			{ "rule_type", FT_UINT, 1, 1 },
			{ "", 0 }
		}
	},
	{
		"change_detect_config_softwares",
		{
			{ "change_detect_config_software_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "change_detect_config_id", FT_UINT, 8, 8 },
			{ "associated_software_id", FT_UINT, 8, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"change_detect_config_targets",
		{
			{ "change_detect_config_target_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "change_detect_config_id", FT_UINT, 8, 8 },
			{ "hostname", FT_CHAR, 0, 200 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"change_detect_configs",
		{
			{ "change_detect_config_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "name", FT_CHAR, 0, 255 },
			{ "escalation_id", FT_UINT, 8, 8 },
			{ "is_escalation_suspendable", FT_INT, 1, 1 },
			{ "activation_approver", FT_CHAR, 0, 8 },
			{ "activation_time", FT_DATETIME, 0, 8 },
			{ "deprecation_approver", FT_CHAR, 0, 8 },
			{ "deprecation_time", FT_DATETIME, 0, 8 },
			{ "status", FT_UINT, 1, 1 },
			{ "description", FT_CHAR, 0, 65535 },
			{ "check_dev", FT_UINT, 1, 1 },
			{ "check_inode", FT_UINT, 1, 1 },
			{ "check_mode", FT_UINT, 1, 1 },
			{ "check_nlink", FT_UINT, 1, 1 },
			{ "check_uid", FT_UINT, 1, 1 },
			{ "check_gid", FT_UINT, 1, 1 },
			{ "check_rdev", FT_UINT, 1, 1 },
			{ "check_mtime", FT_UINT, 1, 1 },
			{ "check_size", FT_UINT, 1, 1 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "deprecation_requester", FT_CHAR, 0, 8 },
			{ "activation_requester", FT_CHAR, 0, 8 },
			{ "record_version_number", FT_INT, 4, 4 },
			{ "owner", FT_CHAR, 0, 8 },
			{ "ignore_attributes", FT_INT, 4, 4 },
			{ "ignore_change_types", FT_INT, 1, 1 },
			{ "", 0 }
		}
	},
	{
		"change_detect_notifications",
		{
			{ "change_detect_notification_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "login", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"change_detect_packages",
		{
			{ "change_detect_package_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "name", FT_CHAR, 0, 255 },
			{ "change_detect_target_id", FT_UINT, 8, 8 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "old_version", FT_CHAR, 0, 50 },
			{ "new_version", FT_CHAR, 0, 50 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"change_detect_targets",
		{
			{ "change_detect_target_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "snapshot_request_id", FT_UINT, 8, 8 },
			{ "hostname", FT_CHAR, 0, 200 },
			{ "host_status", FT_UINT, 1, 1 },
			{ "snapshot_time", FT_DATETIME, 8, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "old_snapshot_time", FT_DATETIME, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"change_detect_unit_details",
		{
			{ "change_detect_unit_detail_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "field_type", FT_UINT, 1, 1 },
			{ "change_detect_unit_id", FT_UINT, 8, 8 },
			{ "old_value", FT_CHAR, 0, 200 },
			{ "new_value", FT_CHAR, 0, 200 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "change_detect_package_id", FT_UINT, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"change_detect_units",
		{
			{ "change_detect_unit_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "path", FT_CHAR, 0, 65535 },
			{ "change_detect_target_id", FT_UINT, 8, 8 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "change_type", FT_UINT, 1, 1 },
			{ "file_mtime", FT_DATETIME, 8, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "is_reconciliation_required", FT_INT, 1, 1 },
			{ "file_type", FT_UINT, 1, 1 },
			{ "filter_request_id", FT_UINT, 0, 8 },
			{ "pending_rec_unit_count", FT_UINT, 4, 4 },
			{ "rec_unit_count", FT_UINT, 4, 4 },
			{ "snapshot_base_path_id", FT_UINT, 8, 8 },
			{ "", 0 }
		}
	},
	{
		"change_detects",
		{
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "escalation_id", FT_UINT, 8, 8 },
			{ "change_detect_config_id", FT_UINT, 8, 8 },
			{ "detect_time", FT_DATETIME, 8, 8 },
			{ "earliest_mtime", FT_DATETIME, 0, 8 },
			{ "resolution_time", FT_DATETIME, 0, 8 },
			{ "status", FT_UINT, 1, 1 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"emergency_references",
		{
			{ "emergency_reference_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "reference_type_code", FT_CHAR, 0, 10 },
			{ "reference", FT_CHAR, 0, 50 },
			{ "url", FT_CHAR, 0, 250 },
			{ "software_change_id", FT_INT, 8, 8 },
			{ "", 0 }
		}
	},
	{
		"escalation_elements",
		{
			{ "escalation_element_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "escalation_id", FT_UINT, 8, 8 },
			{ "login", FT_CHAR, 0, 8 },
			{ "tier", FT_INT, 1, 1 },
			{ "is_primary", FT_INT, 1, 1 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"escalation_suspensions",
		{
			{ "escalation_suspension_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "justification", FT_CHAR, 0, 255 },
			{ "start_time", FT_DATETIME, 8, 8 },
			{ "end_time", FT_DATETIME, 8, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"escalations",
		{
			{ "escalation_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "owner", FT_CHAR, 0, 8 },
			{ "status", FT_UINT, 1, 1 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"filter_constraints",
		{
			{ "filter_constraint_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "filter_request_id", FT_UINT, 8, 8 },
			{ "filter_constraint_combination_id", FT_INT, 4, 4 },
			{ "filter_type", FT_UINT, 0, 1 },
			{ "field_type", FT_UINT, 1, 1 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"filter_patterns",
		{
			{ "filter_pattern_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "pattern_type", FT_UINT, 1, 1 },
			{ "pattern", FT_CHAR, 0, 65535 },
			{ "filter_request_id", FT_UINT, 8, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "negation", FT_INT, 1, 1 },
			{ "", 0 }
		}
	},
	{
		"filter_request_work_logs",
		{
			{ "filter_request_work_log_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "author", FT_CHAR, 0, 8 },
			{ "filter_request_id", FT_UINT, 8, 8 },
			{ "log", FT_CHAR, 0, 65535 },
			{ "log_at", FT_DATETIME, 8, 8 },
			{ "", 0 }
		}
	},
	{
		"filter_requests",
		{
			{ "filter_request_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "requester", FT_CHAR, 0, 8 },
			{ "requested_at", FT_DATETIME, 8, 8 },
			{ "why_happened", FT_CHAR, 0, 65535 },
			{ "why_not_intended_change", FT_CHAR, 0, 65535 },
			{ "change_type", FT_INT, 1, 1 },
			{ "status", FT_INT, 1, 1 },
			{ "resolved_by", FT_CHAR, 0, 8 },
			{ "resolved_at", FT_DATETIME, 0, 8 },
			{ "being_worked_by", FT_CHAR, 0, 8 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "rejected_by", FT_CHAR, 0, 8 },
			{ "rejected_at", FT_DATETIME, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"filter_targets",
		{
			{ "filter_target_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "filter_request_id", FT_UINT, 8, 8 },
			{ "change_detect_target_id", FT_UINT, 8, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"pending_reconciliation_dependencies",
		{
			{ "pending_reconciliation_dependency_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "pending_reconciliation_id", FT_UINT, 8, 8 },
			{ "change_detect_unit_id", FT_UINT, 8, 8 },
			{ "reconciliation_id", FT_UINT, 0, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "", 0 }
		}
	},
	{
		"pending_reconciliation_units",
		{
			{ "pending_reconciliation_unit_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "pending_reconciliation_id", FT_UINT, 8, 8 },
			{ "change_detect_unit_id", FT_UINT, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "", 0 }
		}
	},
	{
		"pending_reconciliations",
		{
			{ "pending_reconciliation_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "release_candidate_id", FT_UINT, 8, 8 },
			{ "status", FT_UINT, 1, 1 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "", 0 }
		}
	},
	{
		"rec_session_units",
		{
			{ "rec_session_unit_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "rec_session_id", FT_UINT, 8, 8 },
			{ "change_detect_unit_id", FT_UINT, 8, 8 },
			{ "change_detect_package_id", FT_UINT, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"rec_sessions",
		{
			{ "rec_session_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "user", FT_CHAR, 0, 8 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "software_change_id", FT_UINT, 8, 8 },
			{ "release_candidate_id", FT_UINT, 8, 8 },
			{ "note", FT_CHAR, 0, 255 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_INT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"reconciliation_attempts",
		{
			{ "reconciliation_attempt_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "release_candidate_id", FT_UINT, 8, 8 },
			{ "deployment_id", FT_CHAR, 0, 50 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "change_detect_target_id", FT_UINT, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"reconciliation_units",
		{
			{ "reconciliation_unit_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "reconciliation_id", FT_UINT, 8, 8 },
			{ "change_detect_target_id", FT_UINT, 8, 8 },
			{ "change_detect_unit_id", FT_UINT, 8, 8 },
			{ "reconciliation_type", FT_UINT, 1, 1 },
			{ "reference_reconciliation_unit_id", FT_UINT, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "change_detect_package_id", FT_UINT, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"reconciliations",
		{
			{ "reconciliation_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "reconciler", FT_CHAR, 0, 8 },
			{ "change_detect_id", FT_UINT, 8, 8 },
			{ "release_candidate_id", FT_UINT, 8, 8 },
			{ "status", FT_UINT, 1, 1 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "start_date", FT_DATETIME, 0, 8 },
			{ "note", FT_CHAR, 0, 255 },
			{ "", 0 }
		}
	},
	{
		"related_deployments",
		{
			{ "related_deployment_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "release_candidate_id", FT_UINT, 8, 8 },
			{ "deployment_id", FT_CHAR, 0, 50 },
			{ "deployment_start_time", FT_DATETIME, 8, 8 },
			{ "releaser", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"release_candidates",
		{
			{ "release_candidate_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "title", FT_CHAR, 0, 255 },
			{ "releaser", FT_CHAR, 0, 8 },
			{ "expected_release_date", FT_DATETIME, 0, 8 },
			{ "release_mgmt_sys_id", FT_UINT, 0, 1 },
			{ "status", FT_UINT, 1, 1 },
			{ "approver", FT_CHAR, 0, 8 },
			{ "approval_datetime", FT_DATETIME, 0, 8 },
			{ "is_validated", FT_CHAR, 1, 1 },
			{ "validation_procedure", FT_CHAR, 0, 65535 },
			{ "validation_result", FT_CHAR, 0, 65535 },
			{ "software_change_id", FT_UINT, 8, 8 },
			{ "associated_software_id", FT_UINT, 4, 4 },
			{ "record_version_number", FT_INT, 4, 4 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "releaser_approved_by", FT_CHAR, 0, 8 },
			{ "releaser_approved_at", FT_DATETIME, 0, 8 },
			{ "releaser_assigned_by", FT_CHAR, 0, 8 },
			{ "releaser_assigned_at", FT_DATETIME, 0, 8 },
			{ "deployment_id", FT_CHAR, 0, 50 },
			{ "build_candidate_id", FT_UINT, 0, 8 },
			{ "deployment_info_complete", FT_INT, 0, 1 },
			{ "deployment_verified", FT_INT, 1, 1 },
			{ "", 0 }
		}
	},
	{
		"release_mgmt_systems",
		{
			{ "release_mgmt_system_id", FT_UINT, 1, 1 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "name", FT_CHAR, 0, 50 },
			{ "description", FT_CHAR, 0, 255 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"release_targets",
		{
			{ "release_target_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "release_candidate_id", FT_UINT, 0, 8 },
			{ "hostname", FT_CHAR, 0, 200 },
			{ "host_status", FT_UINT, 0, 1 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"release_units",
		{
			{ "release_unit_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "release_candidate_id", FT_UINT, 8, 8 },
			{ "file", FT_CHAR, 0, 65535 },
			{ "file_size", FT_UINT, 0, 4 },
			{ "file_date", FT_DATETIME, 0, 8 },
			{ "file_owner", FT_CHAR, 0, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"role_members",
		{
			{ "role_member_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "role", FT_CHAR, 0, 50 },
			{ "member", FT_CHAR, 0, 8 },
			{ "associated_software_id", FT_INT, 4, 4 },
			{ "activated_at", FT_DATETIME, 8, 8 },
			{ "deactivated_at", FT_DATETIME, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "record_version_number", FT_INT, 4, 4 },
			{ "activated_by", FT_CHAR, 0, 8 },
			{ "deactivated_by", FT_CHAR, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"sessions",
		{
			{ "id", FT_INT, 4, 4 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "sessid", FT_CHAR, 0, 255 },
			{ "data", FT_CHAR, 0, 65535 },
			{ "updated_at", FT_DATETIME, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"snapshot_base_paths",
		{
			{ "snapshot_base_path_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "snapshot_request_id", FT_UINT, 8, 8 },
			{ "change_detect_config_id", FT_UINT, 8, 8 },
			{ "change_detect_config_rule_id", FT_UINT, 8, 8 },
			{ "path_type", FT_UINT, 1, 1 },
			{ "path", FT_CHAR, 0, 65535 },
			{ "actual_path", FT_CHAR, 0, 65535 },
			{ "found_in_snapshot", FT_UINT, 0, 1 },
			{ "checksum", FT_CHAR, 0, 65535 },
			{ "checksum_match", FT_INT, 1, 1 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"snapshot_requests",
		{
			{ "snapshot_request_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "change_detect_config_id", FT_UINT, 8, 8 },
			{ "hostname", FT_CHAR, 0, 200 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"software_change_status",
		{
			{ "software_change_status_id", FT_INT, 1, 1 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "name", FT_CHAR, 0, 50 },
			{ "description", FT_CHAR, 0, 200 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "", 0 }
		}
	},
	{
		"software_changes",
		{
			{ "software_change_id", FT_UINT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "associated_software_id", FT_UINT, 4, 4 },
			{ "status", FT_UINT, 1, 1 },
			{ "motivation", FT_CHAR, 0, 200 },
			{ "motivation_detail", FT_CHAR, 0, 65535 },
			{ "ref_software_change_id", FT_UINT, 0, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "reason", FT_INT, 1, 1 },
			{ "status_justification", FT_CHAR, 0, 255 },
			{ "", 0 }
		}
	},
	{
		"software_identifier_types",
		{
			{ "software_identifier_type_id", FT_UINT, 1, 1 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "release_mgmt_system_id", FT_UINT, 1, 1 },
			{ "name", FT_CHAR, 0, 50 },
			{ "status", FT_UINT, 1, 1 },
			{ "description", FT_CHAR, 0, 255 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_UINT, 0, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"user_audit_trails",
		{
			{ "user_audit_trail_id", FT_INT, 8, 8 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "object_class", FT_CHAR, 0, 50 },
			{ "object_id", FT_INT, 8, 8 },
			{ "field_name", FT_CHAR, 0, 50 },
			{ "new_value", FT_CHAR, 0, 65535 },
			{ "updated_by", FT_CHAR, 0, 8 },
			{ "updated_at", FT_DATETIME, 8, 8 },
			{ "record_version_number", FT_INT, 4, 4 },
			{ "", 0 }
		}
	},
	{
		"user_settings",
		{
			{ "user_setting_id", FT_INT, 4, 4 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "user", FT_CHAR, 0, 8 },
			{ "key", FT_CHAR, 0, 50 },
			{ "value", FT_CHAR, 0, 50 },
			{ "record_version_number", FT_INT, 4, 4 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "", 0 }
		}
	},
	{
		"version_control_types",
		{
			{ "version_control_type_id", FT_UINT, 1, 1 },
			{ "DB_TRX_ID", FT_INTERNAL, 6, 6 },
			{ "DB_ROLL_PTR", FT_INTERNAL, 7, 7 },
			{ "name", FT_CHAR, 0, 50 },
			{ "description", FT_CHAR, 0, 200 },
			{ "record_version_number", FT_UINT, 4, 4 },
			{ "creation_date", FT_DATETIME, 8, 8 },
			{ "last_updated_date", FT_DATETIME, 8, 8 },
			{ "created_by", FT_CHAR, 0, 8 },
			{ "last_updated_by", FT_CHAR, 0, 8 },
			{ "", 0 }
		}
	},
};

int table_definitions_cnt = sizeof(table_definitions) / sizeof(table_def_t);

#endif
