/*
   Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved.














   The lines above are intentionally left blank
*/

// MySQL DB access module, for use by plugins and others
// For the module that implements interactive DB functionality see mod_db

#ifndef _MOD_CRUD_TABLE_DELETE_H_
#define _MOD_CRUD_TABLE_DELETE_H_

#include "table_crud_definition.h"

namespace mysh
{
  namespace mysqlx
  {
    class Table;

    /**
    * Handler for Delete operation on Tables.
    */
    class TableDelete : public Table_crud_definition, public boost::enable_shared_from_this<TableDelete>
    {
    public:
      TableDelete(boost::shared_ptr<Table> owner);
    public:
      virtual std::string class_name() const { return "TableDelete"; }
      static boost::shared_ptr<shcore::Object_bridge> create(const shcore::Argument_list &args);
      shcore::Value remove(const shcore::Argument_list &args);
      shcore::Value where(const shcore::Argument_list &args);
      shcore::Value order_by(const shcore::Argument_list &args);
      shcore::Value limit(const shcore::Argument_list &args);
      shcore::Value bind(const shcore::Argument_list &args);

      virtual shcore::Value execute(const shcore::Argument_list &args);
#ifdef DOXYGEN
      TableDelete delete();
      TableDelete where(String searchCondition);
      TableDelete orderBy(List sortExprStr);
      TableDelete limit(Integer numberOfRows);
      TableDelete bind(String name, Value value);
      Result execute();
#endif
    private:
      std::unique_ptr< ::mysqlx::DeleteStatement> _delete_statement;
    };
  };
};

#endif
