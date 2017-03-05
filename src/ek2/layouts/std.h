/* eclean-kernel2
 * (c) 2016 Michał Górny
 * 2-clause BSD license
 */

#pragma once

#ifndef EK2_LAYOUTS_STD_H
#define EK2_LAYOUTS_STD_H 1

#include "ek2/fileset.h"
#include "ek2/layout.h"
#include "ek2/options.h"
#include "ek2/util/directorystream.h"

#include <memory>
#include <unordered_map>
#include <vector>

// Standard flat /boot used for a single system
class StdLayout : public Layout
{
	// keep /boot open for relative actions
	std::shared_ptr<DirectoryStream> boot_dir_;
	// /lib/modules
	std::shared_ptr<DirectoryStream> modules_dir_;

	std::vector<FileSet> kernels_;

public:
	StdLayout(const Options& opts);

	// allocate and construct a new StdLayout
	static std::unique_ptr<Layout> construct(const Options& opts);

	virtual bool find_kernels();

	virtual std::vector<FileSet>& kernels();
	virtual const std::vector<FileSet>& kernels() const;
};

#endif /*EK2_LAYOUTS_STD_H*/
