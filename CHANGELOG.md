# CHANGELOG

## [2.0.2.6] - 2026-06-27

### Infra

- Re-ship libldac included tarball in release, the tarball is bundled in GitHub Actions. Nothing else changes.

## [2.0.2.5] - 2026-06-24

### Changes

- Allow build with CMake 4.0.0 by @heitbaum in https://github.com/EHfive/ldacBT/pull/1
- Drop patch version in soname, built libraries will only have `.so.2.0.2` suffix at most. This is to ‌distinguish between library version and build script version.
- Pin version to 2.0.2.3 in pkgconfig file for compatibility.
