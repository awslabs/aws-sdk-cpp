﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/athena/Athena_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/athena/model/WorkGroupSummary.h>
#include <utility>

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
namespace Athena
{
namespace Model
{
  class AWS_ATHENA_API ListWorkGroupsResult
  {
  public:
    ListWorkGroupsResult();
    ListWorkGroupsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    ListWorkGroupsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>A list of <a>WorkGroupSummary</a> objects that include the names,
     * descriptions, creation times, and states for each workgroup.</p>
     */
    inline const Aws::Vector<WorkGroupSummary>& GetWorkGroups() const{ return m_workGroups; }

    /**
     * <p>A list of <a>WorkGroupSummary</a> objects that include the names,
     * descriptions, creation times, and states for each workgroup.</p>
     */
    inline void SetWorkGroups(const Aws::Vector<WorkGroupSummary>& value) { m_workGroups = value; }

    /**
     * <p>A list of <a>WorkGroupSummary</a> objects that include the names,
     * descriptions, creation times, and states for each workgroup.</p>
     */
    inline void SetWorkGroups(Aws::Vector<WorkGroupSummary>&& value) { m_workGroups = std::move(value); }

    /**
     * <p>A list of <a>WorkGroupSummary</a> objects that include the names,
     * descriptions, creation times, and states for each workgroup.</p>
     */
    inline ListWorkGroupsResult& WithWorkGroups(const Aws::Vector<WorkGroupSummary>& value) { SetWorkGroups(value); return *this;}

    /**
     * <p>A list of <a>WorkGroupSummary</a> objects that include the names,
     * descriptions, creation times, and states for each workgroup.</p>
     */
    inline ListWorkGroupsResult& WithWorkGroups(Aws::Vector<WorkGroupSummary>&& value) { SetWorkGroups(std::move(value)); return *this;}

    /**
     * <p>A list of <a>WorkGroupSummary</a> objects that include the names,
     * descriptions, creation times, and states for each workgroup.</p>
     */
    inline ListWorkGroupsResult& AddWorkGroups(const WorkGroupSummary& value) { m_workGroups.push_back(value); return *this; }

    /**
     * <p>A list of <a>WorkGroupSummary</a> objects that include the names,
     * descriptions, creation times, and states for each workgroup.</p>
     */
    inline ListWorkGroupsResult& AddWorkGroups(WorkGroupSummary&& value) { m_workGroups.push_back(std::move(value)); return *this; }


    /**
     * <p>A token generated by the Athena service that specifies where to continue
     * pagination if a previous request was truncated. To obtain the next set of pages,
     * pass in the <code>NextToken</code> from the response object of the previous page
     * call.</p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p>A token generated by the Athena service that specifies where to continue
     * pagination if a previous request was truncated. To obtain the next set of pages,
     * pass in the <code>NextToken</code> from the response object of the previous page
     * call.</p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextToken = value; }

    /**
     * <p>A token generated by the Athena service that specifies where to continue
     * pagination if a previous request was truncated. To obtain the next set of pages,
     * pass in the <code>NextToken</code> from the response object of the previous page
     * call.</p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextToken = std::move(value); }

    /**
     * <p>A token generated by the Athena service that specifies where to continue
     * pagination if a previous request was truncated. To obtain the next set of pages,
     * pass in the <code>NextToken</code> from the response object of the previous page
     * call.</p>
     */
    inline void SetNextToken(const char* value) { m_nextToken.assign(value); }

    /**
     * <p>A token generated by the Athena service that specifies where to continue
     * pagination if a previous request was truncated. To obtain the next set of pages,
     * pass in the <code>NextToken</code> from the response object of the previous page
     * call.</p>
     */
    inline ListWorkGroupsResult& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p>A token generated by the Athena service that specifies where to continue
     * pagination if a previous request was truncated. To obtain the next set of pages,
     * pass in the <code>NextToken</code> from the response object of the previous page
     * call.</p>
     */
    inline ListWorkGroupsResult& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p>A token generated by the Athena service that specifies where to continue
     * pagination if a previous request was truncated. To obtain the next set of pages,
     * pass in the <code>NextToken</code> from the response object of the previous page
     * call.</p>
     */
    inline ListWorkGroupsResult& WithNextToken(const char* value) { SetNextToken(value); return *this;}

  private:

    Aws::Vector<WorkGroupSummary> m_workGroups;

    Aws::String m_nextToken;
  };

} // namespace Model
} // namespace Athena
} // namespace Aws
