#pragma once

// fininte difference, works good  
float derivatives(float (*func)(float), float x);
// finite sum, works decent but painfully slow at larger ranges
float integral(float (*func)(float),  float lower, float upper);
// finite limit, works good 
float limit((*func)(float), float h);
