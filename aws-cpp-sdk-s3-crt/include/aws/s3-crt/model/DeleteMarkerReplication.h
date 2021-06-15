﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3-crt/S3Crt_EXPORTS.h>
#include <aws/s3-crt/model/DeleteMarkerReplicationStatus.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace S3Crt
{
namespace Model
{

  /**
   * <p>Specifies whether Amazon S3 replicates delete markers. If you specify a
   * <code>Filter</code> in your replication configuration, you must also include a
   * <code>DeleteMarkerReplication</code> element. If your <code>Filter</code>
   * includes a <code>Tag</code> element, the <code>DeleteMarkerReplication</code>
   * <code>Status</code> must be set to Disabled, because Amazon S3 does not support
   * replicating delete markers for tag-based rules. For an example configuration,
   * see <a
   * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/replication-add-config.html#replication-config-min-rule-config">Basic
   * Rule Configuration</a>. </p> <p>For more information about delete marker
   * replication, see <a
   * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/delete-marker-replication.html">Basic
   * Rule Configuration</a>. </p>  <p>If you are using an earlier version of
   * the replication configuration, Amazon S3 handles replication of delete markers
   * differently. For more information, see <a
   * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/replication-add-config.html#replication-backward-compat-considerations">Backward
   * Compatibility</a>.</p> <p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/s3-2006-03-01/DeleteMarkerReplication">AWS
   * API Reference</a></p>
   */
  class AWS_S3CRT_API DeleteMarkerReplication
  {
  public:
    DeleteMarkerReplication();
    DeleteMarkerReplication(const Aws::Utils::Xml::XmlNode& xmlNode);
    DeleteMarkerReplication& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const;


    /**
     * <p>Indicates whether to replicate delete markers.</p>  <p>Indicates
     * whether to replicate delete markers.</p> 
     */
    inline const DeleteMarkerReplicationStatus& GetStatus() const{ return m_status; }

    /**
     * <p>Indicates whether to replicate delete markers.</p>  <p>Indicates
     * whether to replicate delete markers.</p> 
     */
    inline bool StatusHasBeenSet() const { return m_statusHasBeenSet; }

    /**
     * <p>Indicates whether to replicate delete markers.</p>  <p>Indicates
     * whether to replicate delete markers.</p> 
     */
    inline void SetStatus(const DeleteMarkerReplicationStatus& value) { m_statusHasBeenSet = true; m_status = value; }

    /**
     * <p>Indicates whether to replicate delete markers.</p>  <p>Indicates
     * whether to replicate delete markers.</p> 
     */
    inline void SetStatus(DeleteMarkerReplicationStatus&& value) { m_statusHasBeenSet = true; m_status = std::move(value); }

    /**
     * <p>Indicates whether to replicate delete markers.</p>  <p>Indicates
     * whether to replicate delete markers.</p> 
     */
    inline DeleteMarkerReplication& WithStatus(const DeleteMarkerReplicationStatus& value) { SetStatus(value); return *this;}

    /**
     * <p>Indicates whether to replicate delete markers.</p>  <p>Indicates
     * whether to replicate delete markers.</p> 
     */
    inline DeleteMarkerReplication& WithStatus(DeleteMarkerReplicationStatus&& value) { SetStatus(std::move(value)); return *this;}

  private:

    DeleteMarkerReplicationStatus m_status;
    bool m_statusHasBeenSet;
  };

} // namespace Model
} // namespace S3Crt
} // namespace Aws
