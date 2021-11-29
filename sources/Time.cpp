//Copyright 2021 by Winter Solider

#include "Time.h"

Time::Time(Check_type t, std::vector<int64_t>& sizes) {
  Time::type = t;
  int id = 0;
  for (int64_t i=log2(sizes[0]/2); pow(2, i) < 3*sizes[sizes.size()-1]/2; i++)
  {
    id++;
    Check e(id, type, pow(2, i));
    e.run();
    experiments.push_back(e);
  }
}
void Time::print(std::ostream& os) {
  os<< "investigation\n\ttravel_variant: " << to_string(type) << std::endl;
  for (Check& experiment : experiments)
  {
    os << "\texperiment:\n";
    experiment.print(os);
  }
}
