/* Copyright (c) 2026. All rights reserved. */

#pragma once

#include "common/sys/rc.h"

class SQLStageEvent;

/**
 * @brief 删除表的执行器
 */
class DropTableExecutor
{
public:
  DropTableExecutor()          = default;
  virtual ~DropTableExecutor() = default;

  RC execute(SQLStageEvent *sql_event);
};
