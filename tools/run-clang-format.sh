find . -type f ! -path './external/*' ! -path './build*' ! -path './common*' -type f -regex '.*\.\(cpp\|hpp\|h\|cc\|cxx|c\)' | xargs clang-format-10 -i