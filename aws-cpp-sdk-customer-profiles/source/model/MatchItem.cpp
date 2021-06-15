﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/customer-profiles/model/MatchItem.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace CustomerProfiles
{
namespace Model
{

MatchItem::MatchItem() : 
    m_matchIdHasBeenSet(false),
    m_profileIdsHasBeenSet(false)
{
}

MatchItem::MatchItem(JsonView jsonValue) : 
    m_matchIdHasBeenSet(false),
    m_profileIdsHasBeenSet(false)
{
  *this = jsonValue;
}

MatchItem& MatchItem::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("MatchId"))
  {
    m_matchId = jsonValue.GetString("MatchId");

    m_matchIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ProfileIds"))
  {
    Array<JsonView> profileIdsJsonList = jsonValue.GetArray("ProfileIds");
    for(unsigned profileIdsIndex = 0; profileIdsIndex < profileIdsJsonList.GetLength(); ++profileIdsIndex)
    {
      m_profileIds.push_back(profileIdsJsonList[profileIdsIndex].AsString());
    }
    m_profileIdsHasBeenSet = true;
  }

  return *this;
}

JsonValue MatchItem::Jsonize() const
{
  JsonValue payload;

  if(m_matchIdHasBeenSet)
  {
   payload.WithString("MatchId", m_matchId);

  }

  if(m_profileIdsHasBeenSet)
  {
   Array<JsonValue> profileIdsJsonList(m_profileIds.size());
   for(unsigned profileIdsIndex = 0; profileIdsIndex < profileIdsJsonList.GetLength(); ++profileIdsIndex)
   {
     profileIdsJsonList[profileIdsIndex].AsString(m_profileIds[profileIdsIndex]);
   }
   payload.WithArray("ProfileIds", std::move(profileIdsJsonList));

  }

  return payload;
}

} // namespace Model
} // namespace CustomerProfiles
} // namespace Aws
