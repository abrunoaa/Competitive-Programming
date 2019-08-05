typedef long double lf;

inline lf sq(lf x) { return x * x; }

/** Converte latitude-longitude em coordenadas polares **/
struct latlon { lf r, lat, lon; };  // lat e lon em radianos!
struct pt { lf x, y, z; };          // ponto cartesiano

latlon convert(pt p) {
  lf r = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
  return latlon{ r,
                 asin(p.z / r),
                 atan2(p.y, p.x) };
}

pt convert(latlon l) {
  return pt{ l.r * cos(l.lon)* cos(l.lat),
             l.r * sin(l.lon)* cos(l.lat),
             l.r * sin(l.lat) };
}

/** Encontra distância entre dois pontos na terra **/
// fórmula de Haversine =====> LAT-LON EM RADIANOS!!!
lf dist1(lf r, lf lat1, lf lon1, lf lat2, lf lon2) {      // lenta e tem menos precisão
  lf dlon = lon1 - lon2;
  return r * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(dlon));
}

lf dist2(lf r, lf lat1, lf lon1, lf lat2, lf lon2) {
  lf dlat = lat1 - lat2;
  lf dlon = lon1 - lon2;
  lf p1 = sq(sin(dlat / 2.0));
  lf p2 = cos(lat1) * cos(lat2) * sq(sin(dlon / 2.0));
  return r * 2 * asin(sqrt(p1 + p2));
}

lf dist3(lf r, lf lat1, lf lon1, lf lat2, lf lon2) {
  lf dlon = lon1 - lon2;
  lf x = sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(dlon);
  lf p1 = sq(cos(lat2) * sin(dlon));
  lf p2 = sq(cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlon));
  return r * atan2(sqrt(p1 + p2), x);
}

lf dist4(lf r, lf lat1, lf lon1, lf lat2, lf lon2) {
  lf dlat = lat1 - lat2;
  lf dlon = lon1 - lon2;
  lf x = sq(sin(dlat / 2.0)) + cos(lat1) * cos(lat2) * sq(sin(dlon / 2.0));
  return r * 2 * atan2(sqrt(x), sqrt(1.0 - x));
}

lf dist5(lf r, lf lat1, lf lon1, lf lat2, lf lon2) {
  lf dx = cos(lat2) * cos(lon2) - cos(lat1) * cos(lon1);
  lf dy = cos(lat2) * sin(lon2) - cos(lat1) * sin(lon1);
  lf dz = sin(lat2) - sin(lat1);
  lf c = sqrt(dx * dx + dy * dy + dz * dz);
  return r * 2 * asin(c / 2.0);
}
