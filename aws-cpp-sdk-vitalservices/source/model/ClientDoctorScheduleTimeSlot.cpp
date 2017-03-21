﻿/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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
#include <aws/vitalservices/model/ClientDoctorScheduleTimeSlot.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace VitalServices
{
namespace Model
{

ClientDoctorScheduleTimeSlot::ClientDoctorScheduleTimeSlot() : 
    m_timeSlotHasBeenSet(false),
    m_appointmentIdHasBeenSet(false)
{
}

ClientDoctorScheduleTimeSlot::ClientDoctorScheduleTimeSlot(const JsonValue& jsonValue) : 
    m_timeSlotHasBeenSet(false),
    m_appointmentIdHasBeenSet(false)
{
  *this = jsonValue;
}

ClientDoctorScheduleTimeSlot& ClientDoctorScheduleTimeSlot::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("timeSlot"))
  {
    m_timeSlot = jsonValue.GetString("timeSlot");

    m_timeSlotHasBeenSet = true;
  }

  if(jsonValue.ValueExists("appointmentId"))
  {
    m_appointmentId = jsonValue.GetString("appointmentId");

    m_appointmentIdHasBeenSet = true;
  }

  return *this;
}

JsonValue ClientDoctorScheduleTimeSlot::Jsonize() const
{
  JsonValue payload;

  if(m_timeSlotHasBeenSet)
  {
   payload.WithString("timeSlot", m_timeSlot);

  }

  if(m_appointmentIdHasBeenSet)
  {
   payload.WithString("appointmentId", m_appointmentId);

  }

  return payload;
}

} // namespace Model
} // namespace VitalServices
} // namespace Aws