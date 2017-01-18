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
#pragma once
#include <aws/vitalservices/VitalServices_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/vitalservices/model/CancelAppointmentResult_appointment.h>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace VitalServices
{
namespace Model
{
  class AWS_VITALSERVICES_API cancelAppointmentResult
  {
  public:
    cancelAppointmentResult();
    cancelAppointmentResult(const AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    cancelAppointmentResult& operator=(const AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);

    
    inline const Aws::String& GetErrorCode() const{ return m_errorCode; }

    
    inline void SetErrorCode(const Aws::String& value) { m_errorCode = value; }

    
    inline void SetErrorCode(Aws::String&& value) { m_errorCode = value; }

    
    inline void SetErrorCode(const char* value) { m_errorCode.assign(value); }

    
    inline cancelAppointmentResult& WithErrorCode(const Aws::String& value) { SetErrorCode(value); return *this;}

    
    inline cancelAppointmentResult& WithErrorCode(Aws::String&& value) { SetErrorCode(value); return *this;}

    
    inline cancelAppointmentResult& WithErrorCode(const char* value) { SetErrorCode(value); return *this;}

    
    inline const CancelAppointmentResult_appointment& GetAppointment() const{ return m_appointment; }

    
    inline void SetAppointment(const CancelAppointmentResult_appointment& value) { m_appointment = value; }

    
    inline void SetAppointment(CancelAppointmentResult_appointment&& value) { m_appointment = value; }

    
    inline cancelAppointmentResult& WithAppointment(const CancelAppointmentResult_appointment& value) { SetAppointment(value); return *this;}

    
    inline cancelAppointmentResult& WithAppointment(CancelAppointmentResult_appointment&& value) { SetAppointment(value); return *this;}

  private:
    Aws::String m_errorCode;
    CancelAppointmentResult_appointment m_appointment;
  };

} // namespace Model
} // namespace VitalServices
} // namespace Aws
