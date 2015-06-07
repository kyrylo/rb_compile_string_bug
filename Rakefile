require 'rake/extensiontask'
require 'rake/clean'

dlext = RbConfig::CONFIG['DLEXT']

CLEAN.include("ext/**/*.#{dlext}", "ext/**/*.log", "ext/**/*.o",
              "ext/**/*~", "ext/**/*#*", "ext/**/*.obj", "**/*#*", "**/*#*.*",
              "ext/**/*.def", "ext/**/*.pdb", "**/*_flymake*.*", "**/*_flymake", "**/*.rbc")

Rake::ExtensionTask.new do |ext|
  ext.name    = 'rb_compile_string_bug'
  ext.ext_dir = 'ext/rb_compile_string_bug'
  ext.lib_dir = 'lib/rb_compile_string_bug'
end

task :bug do
  system 'ruby -Ilib bug.rb'
end

task :req => [:uninstall, :cleanup, :compile, :gem, :install] do
  # system 'pry -rsystem_navigation'
end
