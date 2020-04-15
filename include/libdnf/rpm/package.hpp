/*
Copyright (C) 2020 Red Hat, Inc.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef LIBDNF_RPM_PACKAGE_HPP
#define LIBDNF_RPM_PACKAGE_HPP


#include "sack.hpp"

#include <string>
#include <vector>

namespace libdnf::rpm {

/// @replaces libdnf/hy-package.h:struct:DnfPackage
/// @replaces dnf:dnf/package.py:class:Package
class Package {
public:
    /// @replaces libdnf/hy-package.h:function:dnf_package_get_id(DnfPackage * pkg)
    PackageId get_id() const noexcept { return id; };

    /// @replaces dnf:dnf/package.py:attribute:Package.name
    /// @replaces libdnf/hy-package.h:function:dnf_package_get_name(DnfPackage *pkg);
    std::string get_name() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.e
    /// @replaces dnf:dnf/package.py:attribute:Package.epoch
    /// @replaces libdnf/hy-package.h:function:dnf_package_get_epoch(DnfPackage *pkg);
    unsigned long get_epoch();

    /// @replaces dnf:dnf/package.py:attribute:Package.v
    /// @replaces dnf:dnf/package.py:attribute:Package.version
    /// @replaces libdnf/hy-package.h:function:dnf_package_get_version(DnfPackage *pkg);
    std::string get_version();

    /// @replaces dnf:dnf/package.py:attribute:Package.r
    /// @replaces dnf:dnf/package.py:attribute:Package.release
    /// @replaces libdnf/hy-package.h:function:dnf_package_get_release(DnfPackage *pkg);
    std::string get_release();

    /// @replaces dnf:dnf/package.py:attribute:Package.a
    /// @replaces dnf:dnf/package.py:attribute:Package.arch
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_arch(DnfPackage * pkg)
    std::string get_arch() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.evr
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_evr(DnfPackage * pkg)
    std::string get_evr() const;

    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_nevra(DnfPackage * pkg)
    std::string get_nevra();

    /// @replaces dnf:dnf/package.py:attribute:Package.group
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_group(DnfPackage * pkg)
    std::string get_group();

    /// If package is installed, return get_install_size(). Return get_download_size() otherwise.
    /// @replaces dnf:dnf/package.py:attribute:Package.size
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_size(DnfPackage * pkg)
    unsigned long long get_size() noexcept;

    /// Return size of an RPM package: <size package="..."/>
    /// @replaces dnf:dnf/package.py:attribute:Package.downloadsize
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_downloadsize(DnfPackage * pkg)
    unsigned long long get_download_size() noexcept;

    /// Return size of an RPM package installed on a system: <size installed="..."/>
    /// @replaces dnf:dnf/package.py:attribute:Package.installsize
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_installsize(DnfPackage * pkg)
    unsigned long long get_install_size() noexcept;

    /// @replaces dnf:dnf/package.py:attribute:Package.license
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_license(DnfPackage * pkg)
    std::string get_license();

    /// @replaces dnf:dnf/package.py:attribute:Package.sourcerpm
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_sourcerpm(DnfPackage * pkg)
    std::string get_sourcerpm();

    /// @replaces dnf:dnf/package.py:attribute:Package.buildtime
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_buildtime(DnfPackage * pkg)
    unsigned long long get_build_time() noexcept;

    std::string get_build_host();

    /// @replaces dnf:dnf/package.py:attribute:Package.packager
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_packager(DnfPackage * pkg)
    std::string get_packager();

    std::string get_vendor();

    /// @replaces dnf:dnf/package.py:attribute:Package.url
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_url(DnfPackage * pkg)
    std::string get_url();

    /// @replaces dnf:dnf/package.py:attribute:Package.summary
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_summary(DnfPackage * pkg)
    std::string get_summary();

    /// @replaces dnf:dnf/package.py:attribute:Package.description
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_description(DnfPackage * pkg)
    std::string get_description();

    /// @replaces dnf:dnf/package.py:attribute:Package.files
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_files(DnfPackage * pkg)
    /// TODO(dmach): files, directories, info about ghost etc. - existing implementation returns incomplete data
    std::vector<std::string> get_files();


/// TODO everything bellow
    
    /// @replaces dnf:dnf/package.py:attribute:Package.changelogs
    /// @replaces libdnf:libdnf/hy-package-private.hpp:function:dnf_package_get_changelogs(DnfPackage * pkg)
    void get_changelogs() const;

    // DEPENDENCIES

    /// @replaces dnf:dnf/package.py:attribute:Package.provides
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_provides(DnfPackage * pkg)
    void get_provides() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.requires
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_requires(DnfPackage * pkg)
    void get_requires() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.requires_pre
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_requires_pre(DnfPackage * pkg)
    void get_requires_pre() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.conflicts
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_conflicts(DnfPackage * pkg)
    void get_conflicts() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.obsoletes
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_obsoletes(DnfPackage * pkg)
    void get_obsoletes() const;

    // TODO(dmach): getBugUrl() not possible due to lack of support in libsolv and metadata?

    // WEAK DEPENDENCIES

    /// @replaces dnf:dnf/package.py:attribute:Package.recommends
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_recommends(DnfPackage * pkg)
    void get_recommends() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.suggests
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_suggests(DnfPackage * pkg)
    void get_suggests() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.enhances
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_enhances(DnfPackage * pkg)
    void get_enhances() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.supplements
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_supplements(DnfPackage * pkg)
    void get_supplements() const;


    // REPODATA

    /// @replaces dnf:dnf/package.py:attribute:Package.repo
    /// @replaces dnf:dnf/package.py:attribute:Package.repoid
    /// @replaces dnf:dnf/package.py:attribute:Package.reponame
    /// @replaces libdnf:libdnf/dnf-package.h:function:dnf_package_get_repo(DnfPackage * pkg)
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_reponame(DnfPackage * pkg)
    void get_repo() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.baseurl
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_baseurl(DnfPackage * pkg)
    std::string get_baseurl() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.location
    /// @replaces dnf:dnf/package.py:attribute:Package.relativepath
    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_location(DnfPackage * pkg)
    std::string get_location() const;


    // SYSTEM

    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_installed(DnfPackage * pkg)
    /// @replaces dnf:dnf/package.py:attribute:Package.installed
    bool is_installed() const;

    /// @replaces dnf:dnf/package.py:method:Package.localPkg(self)
    /// @replaces libdnf:libdnf/dnf-package.h:function:dnf_package_is_local(DnfPackage * pkg)
    bool is_local() const;

    /// For an installed package, return repoid of repo from the package was installed.
    /// For an available package, return an empty string.
    ///
    /// @replaces dnf:dnf/package.py:attribute:Package.ui_from_repo
    /// @replaces libdnf:libdnf/dnf-package.h:function:dnf_package_get_origin(DnfPackage * pkg)
    void get_from_repo_id() const;

    /// @replaces dnf:dnf/package.py:attribute:Package.reason
    void get_reason() const;

    /// @replaces libdnf:libdnf/hy-package.h:function:dnf_package_get_installtime(DnfPackage * pkg)
    void get_install_time() const;

private:
    const char * get_name_cstring() const noexcept;

    /// @return const char* !! Return temporal values !!
    const char * get_epoch_cstring();

    /// @return const char* !! Return temporal values !!
    const char * get_version_cstring() noexcept;

    /// @return const char* !! Return temporal values !!
    const char * get_release_cstring() noexcept;

    const char * get_arch_cstring() const noexcept;

    const char * get_evr_cstring() const noexcept;

    PackageId id = {0};
    Sack * sack;
};


}  // namespace libdnf::rpm

#endif  // LIBDNF_RPM_PACKAGE_HPP
