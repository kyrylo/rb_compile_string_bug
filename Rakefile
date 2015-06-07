require 'rake/extensiontask'
require 'rake/clean'

Rake::ExtensionTask.new do |ext|
  ext.name    = 'rb_compile_string_bug'
  ext.ext_dir = 'ext/rb_compile_string_bug'
  ext.lib_dir = 'lib/rb_compile_string_bug'
end

task :bug do
  system 'ruby bug.rb'
end
