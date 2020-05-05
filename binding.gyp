{
  'targets': [
    {
      'target_name': 'native-modules-coursework',
      'sources': ['src/addon.cc'],
      'cflags!': [
        '-fno-exceptions'
        '-I/usr/local/opt/openssl/include',
        '-L/usr/local/opt/openssl/lib',
        '-lssl'
      ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'link_settings': {
        'libraries': [ '-lopenssl' ],
        'library_dirs': [ '/usr/local/opt/openssl/include' ]
      }
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      }
    }
  ]
}