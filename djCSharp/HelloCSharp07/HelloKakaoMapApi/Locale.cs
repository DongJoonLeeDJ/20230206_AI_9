using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloKakaoMapApi
{
    public class Locale
    {
        public string Name { get; set; }
        public double Lat { get; set; } //Y
        public double Lng { get; set; } //X

        public Locale(string name, double lat, double lng)
        {
            Name = name;
            Lat = lat;
            Lng = lng;
        }

        public override string ToString()
        {
            return Name;
        }
    }
}
