﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/ec2/model/DescribeAddressesAttributeRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::EC2::Model;
using namespace Aws::Utils;

DescribeAddressesAttributeRequest::DescribeAddressesAttributeRequest() : 
    m_allocationIdsHasBeenSet(false),
    m_attribute(AddressAttributeName::NOT_SET),
    m_attributeHasBeenSet(false),
    m_nextTokenHasBeenSet(false),
    m_maxResults(0),
    m_maxResultsHasBeenSet(false),
    m_dryRun(false),
    m_dryRunHasBeenSet(false)
{
}

Aws::String DescribeAddressesAttributeRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=DescribeAddressesAttribute&";
  if(m_allocationIdsHasBeenSet)
  {
    unsigned allocationIdsCount = 1;
    for(auto& item : m_allocationIds)
    {
      ss << "AllocationId." << allocationIdsCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      allocationIdsCount++;
    }
  }

  if(m_attributeHasBeenSet)
  {
    ss << "Attribute=" << AddressAttributeNameMapper::GetNameForAddressAttributeName(m_attribute) << "&";
  }

  if(m_nextTokenHasBeenSet)
  {
    ss << "NextToken=" << StringUtils::URLEncode(m_nextToken.c_str()) << "&";
  }

  if(m_maxResultsHasBeenSet)
  {
    ss << "MaxResults=" << m_maxResults << "&";
  }

  if(m_dryRunHasBeenSet)
  {
    ss << "DryRun=" << std::boolalpha << m_dryRun << "&";
  }

  ss << "Version=2016-11-15";
  return ss.str();
}


void  DescribeAddressesAttributeRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
