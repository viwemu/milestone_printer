#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint milestone_printer.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'milestone_printer'
  s.version          = '0.0.2'
  s.summary          = 'A new Flutter project.'
  s.description      = <<-DESC
A new Flutter project.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.dependency 'Flutter'
  s.platform = :ios, '8.0'

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.0'
  s.preserve_paths = 'libRTPrinterSDK.a'
  s.xcconfig = {
       # here on LDFLAG, I had to set -l and then the library name (without lib prefix although the file name has it).
#      'OTHER_LDFLAGS' => '$(SRCROOT)/../../../ios/libRTPrinterSDK.a',
      'OTHER_LDFLAGS' => '/Users/macintosh/Documents/flutter_project/milestone_printer/ios/libRTPrinterSDK.a',
#      'USER_HEADER_SEARCH_PATHS' => '"${PROJECT_DIR}/.."/',
      "LIBRARY_SEARCH_PATHS" => '$(SRCROOT)/../../../ios/libRTPrinterSDK'
    }
  s.vendored_libraries = '$(SRCROOT)/../../../ios/libRTPrinterSDK.a'
  s.public_header_files = 'Classes/**/*.h'
  s.libraries = 'z'
  s.frameworks = 'CoreBluetooth', 'CFNetwork'
  
end
