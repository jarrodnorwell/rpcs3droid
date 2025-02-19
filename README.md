# rpcs3droid
Attempt at running RPCS3 on Android natively via Android Studio

## Building
> [!NOTE]
> Building is currently unavailable

CMake successfully configures however, when building it will fail and throw a bunch of clang errors

- [ ] libusb is not built for Android but is possible ([**guide**](https://github.com/libusb/libusb/wiki/Android))
- [ ] wolfssl is not built for Android but is possible ([**guide**](https://www.wolfssl.com/how-to-build-wolfssl-for-android))
- [ ] pthread throws errors related to `long` and `u64`
- [ ] OpenSSL is set up manually, needs fixing
- [ ] zlib currently fails

# Disclaimer
> [!CAUTION]
> Contributions will not be accepted, please do not create pull requests as they will be closed

# Licensing
### RPCS3 ([GPLv2](LICENSE))
