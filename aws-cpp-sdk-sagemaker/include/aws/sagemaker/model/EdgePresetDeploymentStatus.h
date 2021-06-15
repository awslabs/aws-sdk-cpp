﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/sagemaker/SageMaker_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace SageMaker
{
namespace Model
{
  enum class EdgePresetDeploymentStatus
  {
    NOT_SET,
    COMPLETED,
    FAILED
  };

namespace EdgePresetDeploymentStatusMapper
{
AWS_SAGEMAKER_API EdgePresetDeploymentStatus GetEdgePresetDeploymentStatusForName(const Aws::String& name);

AWS_SAGEMAKER_API Aws::String GetNameForEdgePresetDeploymentStatus(EdgePresetDeploymentStatus value);
} // namespace EdgePresetDeploymentStatusMapper
} // namespace Model
} // namespace SageMaker
} // namespace Aws
