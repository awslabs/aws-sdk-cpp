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

#include <aws/medialive/model/Scte35SpliceInsertWebDeliveryAllowedBehavior.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace MediaLive
  {
    namespace Model
    {
      namespace Scte35SpliceInsertWebDeliveryAllowedBehaviorMapper
      {

        static const int FOLLOW_HASH = HashingUtils::HashString("FOLLOW");
        static const int IGNORE_HASH = HashingUtils::HashString("IGNORE");


        Scte35SpliceInsertWebDeliveryAllowedBehavior GetScte35SpliceInsertWebDeliveryAllowedBehaviorForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == FOLLOW_HASH)
          {
            return Scte35SpliceInsertWebDeliveryAllowedBehavior::FOLLOW;
          }
          else if (hashCode == IGNORE_HASH)
          {
            return Scte35SpliceInsertWebDeliveryAllowedBehavior::IGNORE;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<Scte35SpliceInsertWebDeliveryAllowedBehavior>(hashCode);
          }

          return Scte35SpliceInsertWebDeliveryAllowedBehavior::NOT_SET;
        }

        Aws::String GetNameForScte35SpliceInsertWebDeliveryAllowedBehavior(Scte35SpliceInsertWebDeliveryAllowedBehavior enumValue)
        {
          switch(enumValue)
          {
          case Scte35SpliceInsertWebDeliveryAllowedBehavior::FOLLOW:
            return "FOLLOW";
          case Scte35SpliceInsertWebDeliveryAllowedBehavior::IGNORE:
            return "IGNORE";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace Scte35SpliceInsertWebDeliveryAllowedBehaviorMapper
    } // namespace Model
  } // namespace MediaLive
} // namespace Aws
