﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/elasticache/model/ModifyCacheClusterRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::ElastiCache::Model;
using namespace Aws::Utils;

ModifyCacheClusterRequest::ModifyCacheClusterRequest() : 
    m_cacheClusterIdHasBeenSet(false),
    m_numCacheNodes(0),
    m_numCacheNodesHasBeenSet(false),
    m_cacheNodeIdsToRemoveHasBeenSet(false),
    m_aZMode(AZMode::NOT_SET),
    m_aZModeHasBeenSet(false),
    m_newAvailabilityZonesHasBeenSet(false),
    m_cacheSecurityGroupNamesHasBeenSet(false),
    m_securityGroupIdsHasBeenSet(false),
    m_preferredMaintenanceWindowHasBeenSet(false),
    m_notificationTopicArnHasBeenSet(false),
    m_cacheParameterGroupNameHasBeenSet(false),
    m_notificationTopicStatusHasBeenSet(false),
    m_applyImmediately(false),
    m_applyImmediatelyHasBeenSet(false),
    m_engineVersionHasBeenSet(false),
    m_autoMinorVersionUpgrade(false),
    m_autoMinorVersionUpgradeHasBeenSet(false),
    m_snapshotRetentionLimit(0),
    m_snapshotRetentionLimitHasBeenSet(false),
    m_snapshotWindowHasBeenSet(false),
    m_cacheNodeTypeHasBeenSet(false),
    m_authTokenHasBeenSet(false),
    m_authTokenUpdateStrategy(AuthTokenUpdateStrategyType::NOT_SET),
    m_authTokenUpdateStrategyHasBeenSet(false),
    m_logDeliveryConfigurationsHasBeenSet(false)
{
}

Aws::String ModifyCacheClusterRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=ModifyCacheCluster&";
  if(m_cacheClusterIdHasBeenSet)
  {
    ss << "CacheClusterId=" << StringUtils::URLEncode(m_cacheClusterId.c_str()) << "&";
  }

  if(m_numCacheNodesHasBeenSet)
  {
    ss << "NumCacheNodes=" << m_numCacheNodes << "&";
  }

  if(m_cacheNodeIdsToRemoveHasBeenSet)
  {
    unsigned cacheNodeIdsToRemoveCount = 1;
    for(auto& item : m_cacheNodeIdsToRemove)
    {
      ss << "CacheNodeIdsToRemove.member." << cacheNodeIdsToRemoveCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      cacheNodeIdsToRemoveCount++;
    }
  }

  if(m_aZModeHasBeenSet)
  {
    ss << "AZMode=" << AZModeMapper::GetNameForAZMode(m_aZMode) << "&";
  }

  if(m_newAvailabilityZonesHasBeenSet)
  {
    unsigned newAvailabilityZonesCount = 1;
    for(auto& item : m_newAvailabilityZones)
    {
      ss << "NewAvailabilityZones.member." << newAvailabilityZonesCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      newAvailabilityZonesCount++;
    }
  }

  if(m_cacheSecurityGroupNamesHasBeenSet)
  {
    unsigned cacheSecurityGroupNamesCount = 1;
    for(auto& item : m_cacheSecurityGroupNames)
    {
      ss << "CacheSecurityGroupNames.member." << cacheSecurityGroupNamesCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      cacheSecurityGroupNamesCount++;
    }
  }

  if(m_securityGroupIdsHasBeenSet)
  {
    unsigned securityGroupIdsCount = 1;
    for(auto& item : m_securityGroupIds)
    {
      ss << "SecurityGroupIds.member." << securityGroupIdsCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      securityGroupIdsCount++;
    }
  }

  if(m_preferredMaintenanceWindowHasBeenSet)
  {
    ss << "PreferredMaintenanceWindow=" << StringUtils::URLEncode(m_preferredMaintenanceWindow.c_str()) << "&";
  }

  if(m_notificationTopicArnHasBeenSet)
  {
    ss << "NotificationTopicArn=" << StringUtils::URLEncode(m_notificationTopicArn.c_str()) << "&";
  }

  if(m_cacheParameterGroupNameHasBeenSet)
  {
    ss << "CacheParameterGroupName=" << StringUtils::URLEncode(m_cacheParameterGroupName.c_str()) << "&";
  }

  if(m_notificationTopicStatusHasBeenSet)
  {
    ss << "NotificationTopicStatus=" << StringUtils::URLEncode(m_notificationTopicStatus.c_str()) << "&";
  }

  if(m_applyImmediatelyHasBeenSet)
  {
    ss << "ApplyImmediately=" << std::boolalpha << m_applyImmediately << "&";
  }

  if(m_engineVersionHasBeenSet)
  {
    ss << "EngineVersion=" << StringUtils::URLEncode(m_engineVersion.c_str()) << "&";
  }

  if(m_autoMinorVersionUpgradeHasBeenSet)
  {
    ss << "AutoMinorVersionUpgrade=" << std::boolalpha << m_autoMinorVersionUpgrade << "&";
  }

  if(m_snapshotRetentionLimitHasBeenSet)
  {
    ss << "SnapshotRetentionLimit=" << m_snapshotRetentionLimit << "&";
  }

  if(m_snapshotWindowHasBeenSet)
  {
    ss << "SnapshotWindow=" << StringUtils::URLEncode(m_snapshotWindow.c_str()) << "&";
  }

  if(m_cacheNodeTypeHasBeenSet)
  {
    ss << "CacheNodeType=" << StringUtils::URLEncode(m_cacheNodeType.c_str()) << "&";
  }

  if(m_authTokenHasBeenSet)
  {
    ss << "AuthToken=" << StringUtils::URLEncode(m_authToken.c_str()) << "&";
  }

  if(m_authTokenUpdateStrategyHasBeenSet)
  {
    ss << "AuthTokenUpdateStrategy=" << AuthTokenUpdateStrategyTypeMapper::GetNameForAuthTokenUpdateStrategyType(m_authTokenUpdateStrategy) << "&";
  }

  if(m_logDeliveryConfigurationsHasBeenSet)
  {
    unsigned logDeliveryConfigurationsCount = 1;
    for(auto& item : m_logDeliveryConfigurations)
    {
      item.OutputToStream(ss, "LogDeliveryConfigurations.member.", logDeliveryConfigurationsCount, "");
      logDeliveryConfigurationsCount++;
    }
  }

  ss << "Version=2015-02-02";
  return ss.str();
}


void  ModifyCacheClusterRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
