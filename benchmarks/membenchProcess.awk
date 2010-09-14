BEGIN {
   getline version
   getline header
   outHeader[1] = "Benchmark"
   data[1, 1] = ""
   line = 0
   col = 1
   row = 1
   lastcpu = -1
   while(0 != getline) {
      split($0, a, /"?\t"?/)
      name  = substr(a[1], 2)
      if(length(filter) == 0 || index(name, filter) == 1) {
         cpu   = a[3]
         value = a[valueIndex]

         if(cpu != lastcpu) {
            row = 1
            lastcpu = cpu
            ++col
            outHeader[col] = "CPU" cpu
         }
         data[row, 1] = name
         if(invert) {
            data[row, col] = 1.0 / value
         } else {
            data[row, col] = value
         }
         ++row
      }
   }
   for(i = 1; i <= length(outHeader); ++i) {
      printf("\"%s\"\t", outHeader[i])
   }
   print ""
   for(r = 1; r < row; ++r) {
      printf("\"%s\"\t", data[r, 1]);
      for(c = 2; c <= col; ++c) {
         printf("%f\t", data[r, c]);
      }
      print ""
   }
}
# vim: sw=3 et
