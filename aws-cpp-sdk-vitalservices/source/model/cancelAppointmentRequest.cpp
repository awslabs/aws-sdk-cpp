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
#include <aws/vitalservices/model/cancelAppointmentRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::VitalServices::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

cancelAppointmentRequest::cancelAppointmentRequest() : 
    m_appointmentIdHasBeenSet(false),
    m_lateCancellation(false),
    m_lateCancellationHasBeenSet(false)
{
}

Aws::String cancelAppointmentRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_appointmentIdHasBeenSet)
  {
   payload.WithString("appointmentId", m_appointmentId);

  }

  if(m_lateCancellationHasBeenSet)
  {
   payload.WithBool("lateCancellation", m_lateCancellation);

  }

  return payload.WriteReadable();
}



