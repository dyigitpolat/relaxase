file(REMOVE_RECURSE
  "libschifra.a"
  "libschifra.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/schifra.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
