file(REMOVE_RECURSE
  "libkaacpp_s.pdb"
  "libkaacpp_s.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang)
  include(CMakeFiles/kaacpp_s.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
