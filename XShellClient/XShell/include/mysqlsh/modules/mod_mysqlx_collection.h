/*
   Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved.














   The lines above are intentionally left blank
*/

// Interactive Table access module
// (the one exposed as the table members of the db object in the shell)

#ifndef _MOD_MYSQLX_COLLECTION_H_
#define _MOD_MYSQLX_COLLECTION_H_

#include "base_database_object.h"
#include "shellcore/types.h"
#include "shellcore/types_cpp.h"
#include "mysqlx_crud.h"

#include "mod_mysqlx_collection_add.h"
#include "mod_mysqlx_collection_remove.h"
#include "mod_mysqlx_collection_find.h"
#include "mod_mysqlx_collection_modify.h"

namespace mysh
{
  namespace mysqlx
  {
    class Schema;

    /**
    * Represents a Collection on an Schema, retrieved with session created using the mysqlx module.
    */
    class Collection : public DatabaseObject, public boost::enable_shared_from_this<Collection>
    {
    public:
      Collection(boost::shared_ptr<Schema> owner, const std::string &name);
      Collection(boost::shared_ptr<const Schema> owner, const std::string &name);
      ~Collection();

      virtual std::string class_name() const { return "Collection"; }

#ifdef DOXYGEN
      CollectionAdd add(Document doc);
      CollectionAdd add(List documents);
      CollectionFind find(String searchCriteria);
      CollectionRemove remove(String searchCondition);
      CollectionModify modify(String searchCondition);
      CollectionCreateIndex createIndex(String name);
      CollectionCreateIndex createIndex(String name, IndexType type);
      CollectionDropIndex dropIndex(String name);
#endif

    private:
      shcore::Value add_(const shcore::Argument_list &args);
      shcore::Value find_(const shcore::Argument_list &args);
      shcore::Value modify_(const shcore::Argument_list &args);
      shcore::Value remove_(const shcore::Argument_list &args);
      shcore::Value create_index_(const shcore::Argument_list &args);
      shcore::Value drop_index_(const shcore::Argument_list &args);

      void init();
      boost::shared_ptr< ::mysqlx::Collection> _collection_impl;

      // Allows initial functions on the CRUD operations
      friend shcore::Value CollectionAdd::add(const shcore::Argument_list &args);
      friend shcore::Value CollectionFind::find(const shcore::Argument_list &args);
      friend shcore::Value CollectionRemove::remove(const shcore::Argument_list &args);
      friend shcore::Value CollectionModify::modify(const shcore::Argument_list &args);
    };
  }
}

#endif
