file(REMOVE_RECURSE
  "libkaacpp.pdb"
  "libkaacpp.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang)
  include(CMakeFiles/kaacpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
