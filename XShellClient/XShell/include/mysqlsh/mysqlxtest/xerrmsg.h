/*
   Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved.










   The lines above are intentionally left blank
*/


#ifndef _MYSQLX_ERRORS_H_
#define _MYSQLX_ERRORS_H_

#define ER_X_SERVICE_ERROR        5010
#define ER_X_SESSION              5011
#define ER_X_INVALID_ARGUMENT     5012
#define ER_X_MISSING_ARGUMENT     5013
#define ER_X_BAD_INSERT_DATA      5014

#define ER_X_CMD_NUM_ARGUMENTS    5015
#define ER_X_CMD_ARGUMENT_TYPE    5016
#define ER_X_CMD_ARGUMENT_VALUE   5017

#define ER_X_BAD_UPDATE_DATA      5050
#define ER_X_BAD_TYPE_OF_UPDATE   5051
#define ER_X_BAD_COLUMN_TO_UPDATE 5052
#define ER_X_BAD_MEMBER_TO_UPDATE 5053

#define ER_X_BAD_STATEMENT_ID     5110
#define ER_X_BAD_CURSOR_ID        5111

#define ER_X_BAD_SCHEMA           5112
#define ER_X_BAD_TABLE            5113
#define ER_X_BAD_PROJECTION       5114

#define ER_X_DOC_ID_MISSING       5115
#define ER_X_DOC_ID_DUPLICATE     5116
#define ER_X_DOC_REQUIRED_FIELD_MISSING 5117

#define ER_X_PROJ_BAD_KEY_NAME    5120
#define ER_X_BAD_DOC_PATH         5121

#define ER_X_CURSOR_EXISTS        5122

#define ER_X_EXPR_BAD_OPERATOR    5150
#define ER_X_EXPR_BAD_NUM_ARGS    5151
#define ER_X_EXPR_MISSING_ARG     5152
#define ER_X_EXPR_BAD_TYPE_VALUE  5153
#define ER_X_EXPR_BAD_VALUE       5154

#define ER_X_INVALID_COLLECTION   5156

#define ER_X_INVALID_ADMIN_COMMAND 5157

#define ER_X_EXPECT_NOT_OPEN       5158
#define ER_X_EXPECT_FAILED        5159
#define ER_X_EXPECT_BAD_CONDITION  5160
#define ER_X_EXPECT_BAD_CONDITION_VALUE 5161

#define ER_X_INVALID_NAMESPACE    5162

#define ER_X_BAD_NOTICE           5163
#define ER_X_CANNOT_DISABLE_NOTICE   5164

#define ER_X_BAD_CONFIGURATION    5165

#define ER_X_BAD_PIPE             5166

#endif // _MYSQLX_ERRORS_H_
