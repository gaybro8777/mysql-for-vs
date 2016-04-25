/*
   Copyright (c) 2014, 2015, Oracle and/or its affiliates. All rights reserved.














   The lines above are intentionally left blank
*/

#ifndef __mysh__utils_general__
#define __mysh__utils_general__

#include "shellcore/common.h"
#include "shellcore/types.h"
#include <string>

namespace shcore
{
  bool SHCORE_PUBLIC is_valid_identifier(const std::string& name);
  std::string SHCORE_PUBLIC build_connection_string(Value::Map_type_ref data, bool with_password);
  void SHCORE_PUBLIC conn_str_cat_ssl_data(std::string& uri, const std::string& ssl_ca, const std::string& ssl_cert, const std::string& ssl_key);
  void SHCORE_PUBLIC parse_mysql_connstring(const std::string &connstring,
                                            std::string &protocol, std::string &user, std::string &password,
                                            std::string &host, int &port, std::string &sock,
                                            std::string &db, int &pwd_found, std::string& ssl_ca, std::string& ssl_cert, std::string& ssl_key);

  Value::Map_type_ref SHCORE_PUBLIC get_connection_data(const std::string &uri);
  void SHCORE_PUBLIC update_connection_data(Value::Map_type_ref data,
                                            const std::string &user, const char *password,
                                            const std::string &host, int &port, const std::string& sock,
                                            const std::string &database,
                                            bool ssl, const std::string &ssl_ca,
                                            const std::string &ssl_cert, const std::string &ssl_key,
                                            const std::string &auth_method);

  void SHCORE_PUBLIC set_default_connection_data(Value::Map_type_ref data, int defaultPort);

  std::string SHCORE_PUBLIC get_system_user();

  // Convenience function to simply validate the URI
  bool SHCORE_PUBLIC validate_uri(const std::string &uri);

  std::string SHCORE_PUBLIC strip_password(const std::string &connstring);

  std::string SHCORE_PUBLIC strip_ssl_args(const std::string &connstring);

  char SHCORE_PUBLIC *mysh_get_stdin_password(const char *prompt);
}

#endif /* defined(__mysh__utils_general__) */
