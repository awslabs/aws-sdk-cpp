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
#include <aws/vitalservices/model/GetLoggedInUserResult_user.h>
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

GetLoggedInUserResult_user::GetLoggedInUserResult_user() : 
    m_doctorIdHasBeenSet(false),
    m_idHasBeenSet(false),
    m_profilePhotoUrlHasBeenSet(false),
    m_stripeCustomerIdHasBeenSet(false),
    m_firstNameHasBeenSet(false),
    m_lastNameHasBeenSet(false),
    m_emailHasBeenSet(false),
    m_mobileNumberHasBeenSet(false)
{
}

GetLoggedInUserResult_user::GetLoggedInUserResult_user(const JsonValue& jsonValue) : 
    m_doctorIdHasBeenSet(false),
    m_idHasBeenSet(false),
    m_profilePhotoUrlHasBeenSet(false),
    m_stripeCustomerIdHasBeenSet(false),
    m_firstNameHasBeenSet(false),
    m_lastNameHasBeenSet(false),
    m_emailHasBeenSet(false),
    m_mobileNumberHasBeenSet(false)
{
  *this = jsonValue;
}

GetLoggedInUserResult_user& GetLoggedInUserResult_user::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("doctorId"))
  {
    m_doctorId = jsonValue.GetString("doctorId");

    m_doctorIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("id"))
  {
    m_id = jsonValue.GetString("id");

    m_idHasBeenSet = true;
  }

  if(jsonValue.ValueExists("profilePhotoUrl"))
  {
    m_profilePhotoUrl = jsonValue.GetString("profilePhotoUrl");

    m_profilePhotoUrlHasBeenSet = true;
  }

  if(jsonValue.ValueExists("stripeCustomerId"))
  {
    m_stripeCustomerId = jsonValue.GetString("stripeCustomerId");

    m_stripeCustomerIdHasBeenSet = true;
  }

  if(jsonValue.ValueExists("firstName"))
  {
    m_firstName = jsonValue.GetString("firstName");

    m_firstNameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("lastName"))
  {
    m_lastName = jsonValue.GetString("lastName");

    m_lastNameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("email"))
  {
    m_email = jsonValue.GetString("email");

    m_emailHasBeenSet = true;
  }

  if(jsonValue.ValueExists("mobileNumber"))
  {
    m_mobileNumber = jsonValue.GetString("mobileNumber");

    m_mobileNumberHasBeenSet = true;
  }

  return *this;
}

JsonValue GetLoggedInUserResult_user::Jsonize() const
{
  JsonValue payload;

  if(m_doctorIdHasBeenSet)
  {
   payload.WithString("doctorId", m_doctorId);

  }

  if(m_idHasBeenSet)
  {
   payload.WithString("id", m_id);

  }

  if(m_profilePhotoUrlHasBeenSet)
  {
   payload.WithString("profilePhotoUrl", m_profilePhotoUrl);

  }

  if(m_stripeCustomerIdHasBeenSet)
  {
   payload.WithString("stripeCustomerId", m_stripeCustomerId);

  }

  if(m_firstNameHasBeenSet)
  {
   payload.WithString("firstName", m_firstName);

  }

  if(m_lastNameHasBeenSet)
  {
   payload.WithString("lastName", m_lastName);

  }

  if(m_emailHasBeenSet)
  {
   payload.WithString("email", m_email);

  }

  if(m_mobileNumberHasBeenSet)
  {
   payload.WithString("mobileNumber", m_mobileNumber);

  }

  return payload;
}

} // namespace Model
} // namespace VitalServices
} // namespace Aws