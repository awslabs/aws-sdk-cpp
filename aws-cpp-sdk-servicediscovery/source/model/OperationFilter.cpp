﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/servicediscovery/model/OperationFilter.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace ServiceDiscovery
{
namespace Model
{

OperationFilter::OperationFilter() : 
    m_name(OperationFilterName::NOT_SET),
    m_nameHasBeenSet(false),
    m_valuesHasBeenSet(false),
    m_condition(FilterCondition::NOT_SET),
    m_conditionHasBeenSet(false)
{
}

OperationFilter::OperationFilter(const JsonValue& jsonValue) : 
    m_name(OperationFilterName::NOT_SET),
    m_nameHasBeenSet(false),
    m_valuesHasBeenSet(false),
    m_condition(FilterCondition::NOT_SET),
    m_conditionHasBeenSet(false)
{
  *this = jsonValue;
}

OperationFilter& OperationFilter::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("Name"))
  {
    m_name = OperationFilterNameMapper::GetOperationFilterNameForName(jsonValue.GetString("Name"));

    m_nameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Values"))
  {
    Array<JsonValue> valuesJsonList = jsonValue.GetArray("Values");
    for(unsigned valuesIndex = 0; valuesIndex < valuesJsonList.GetLength(); ++valuesIndex)
    {
      m_values.push_back(valuesJsonList[valuesIndex].AsString());
    }
    m_valuesHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Condition"))
  {
    m_condition = FilterConditionMapper::GetFilterConditionForName(jsonValue.GetString("Condition"));

    m_conditionHasBeenSet = true;
  }

  return *this;
}

JsonValue OperationFilter::Jsonize() const
{
  JsonValue payload;

  if(m_nameHasBeenSet)
  {
   payload.WithString("Name", OperationFilterNameMapper::GetNameForOperationFilterName(m_name));
  }

  if(m_valuesHasBeenSet)
  {
   Array<JsonValue> valuesJsonList(m_values.size());
   for(unsigned valuesIndex = 0; valuesIndex < valuesJsonList.GetLength(); ++valuesIndex)
   {
     valuesJsonList[valuesIndex].AsString(m_values[valuesIndex]);
   }
   payload.WithArray("Values", std::move(valuesJsonList));

  }

  if(m_conditionHasBeenSet)
  {
   payload.WithString("Condition", FilterConditionMapper::GetNameForFilterCondition(m_condition));
  }

  return payload;
}

} // namespace Model
} // namespace ServiceDiscovery
} // namespace Aws
