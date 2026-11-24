/* Copyright (c) 2026. All rights reserved. */

#include "sql/stmt/drop_table_stmt.h"

#include "common/lang/string.h"
#include "storage/db/db.h"

RC DropTableStmt::create(Db *db, const DropTableSqlNode &drop_table, Stmt *&stmt)
{
  stmt = nullptr;
  if (db == nullptr || common::is_blank(drop_table.relation_name.c_str())) {
    return RC::INVALID_ARGUMENT;
  }

  if (db->find_table(drop_table.relation_name.c_str()) == nullptr) {
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  stmt = new DropTableStmt(drop_table.relation_name);
  return RC::SUCCESS;
}
