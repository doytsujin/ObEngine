#include <array>
#include <cmath>

#include <Graphics/Color.hpp>
#include <Graphics/Exceptions.hpp>
#include <Utils/MathUtils.hpp>

namespace obe::graphics
{
    Color Color::AliceBlue(240, 248, 255);
    Color Color::AntiqueWhite(250, 235, 215);
    Color Color::Aqua(0, 255, 255);
    Color Color::Aquamarine(127, 255, 212);
    Color Color::Azure(240, 255, 255);
    Color Color::Beige(245, 245, 220);
    Color Color::Bisque(255, 228, 196);
    Color Color::Black(0, 0, 0);
    Color Color::BlanchedAlmond(255, 235, 205);
    Color Color::Blue(0, 0, 255);
    Color Color::BlueViolet(138, 43, 226);
    Color Color::Brown(165, 42, 42);
    Color Color::BurlyWood(222, 184, 135);
    Color Color::CadetBlue(95, 158, 160);
    Color Color::Chartreuse(127, 255, 0);
    Color Color::Chocolate(210, 105, 30);
    Color Color::Coral(255, 127, 80);
    Color Color::CornflowerBlue(100, 149, 237);
    Color Color::Cornsilk(255, 248, 220);
    Color Color::Crimson(220, 20, 60);
    Color Color::Cyan(0, 255, 255);
    Color Color::DarkBlue(0, 0, 139);
    Color Color::DarkCyan(0, 139, 139);
    Color Color::DarkGoldenrod(184, 134, 11);
    Color Color::DarkGray(169, 169, 169);
    Color Color::DarkGreen(0, 100, 0);
    Color Color::DarkKhaki(189, 183, 107);
    Color Color::DarkMagenta(139, 0, 139);
    Color Color::DarkOliveGreen(85, 107, 47);
    Color Color::DarkOrange(255, 140, 0);
    Color Color::DarkOrchid(153, 50, 204);
    Color Color::DarkRed(139, 0, 0);
    Color Color::DarkSalmon(233, 150, 122);
    Color Color::DarkSeaGreen(143, 188, 139);
    Color Color::DarkSlateBlue(72, 61, 139);
    Color Color::DarkSlateGray(47, 79, 79);
    Color Color::DarkTurquoise(0, 206, 209);
    Color Color::DarkViolet(148, 0, 211);
    Color Color::DeepPink(255, 20, 147);
    Color Color::DeepSkyBlue(0, 191, 255);
    Color Color::DimGray(105, 105, 105);
    Color Color::DodgerBlue(30, 144, 255);
    Color Color::FireBrick(178, 34, 34);
    Color Color::FloralWhite(255, 250, 240);
    Color Color::ForestGreen(34, 139, 34);
    Color Color::Fuchsia(255, 0, 255);
    Color Color::Gainsboro(220, 220, 220);
    Color Color::GhostWhite(248, 248, 255);
    Color Color::Gold(255, 215, 0);
    Color Color::Goldenrod(218, 165, 32);
    Color Color::Gray(128, 128, 128);
    Color Color::Green(0, 128, 0);
    Color Color::GreenYellow(173, 255, 47);
    Color Color::HoneyDew(240, 255, 240);
    Color Color::HotPink(255, 105, 180);
    Color Color::IndianRed(205, 92, 92);
    Color Color::Indigo(75, 0, 130);
    Color Color::Ivory(255, 255, 240);
    Color Color::Khaki(240, 230, 140);
    Color Color::Lavender(230, 230, 250);
    Color Color::LavenderBlush(255, 240, 245);
    Color Color::LawnGreen(124, 252, 0);
    Color Color::LemonChiffon(255, 250, 205);
    Color Color::LightBlue(173, 216, 230);
    Color Color::LightCoral(240, 128, 128);
    Color Color::LightCyan(224, 255, 255);
    Color Color::LightGoldenrodYellow(250, 250, 210);
    Color Color::LightGray(211, 211, 211);
    Color Color::LightGreen(144, 238, 144);
    Color Color::LightPink(255, 182, 193);
    Color Color::LightSalmon(255, 160, 122);
    Color Color::LightSeaGreen(32, 178, 170);
    Color Color::LightSkyBlue(135, 206, 250);
    Color Color::LightSlateGray(119, 136, 153);
    Color Color::LightSteelBlue(176, 196, 222);
    Color Color::LightYellow(255, 255, 224);
    Color Color::Lime(0, 255, 0);
    Color Color::LimeGreen(50, 205, 50);
    Color Color::Linen(250, 240, 230);
    Color Color::Magenta(255, 0, 255);
    Color Color::Maroon(128, 0, 0);
    Color Color::MediumAquamarine(102, 205, 170);
    Color Color::MediumBlue(0, 0, 205);
    Color Color::MediumOrchid(186, 85, 211);
    Color Color::MediumPurple(147, 112, 219);
    Color Color::MediumSeaGreen(60, 179, 113);
    Color Color::MediumSlateBlue(123, 104, 238);
    Color Color::MediumSpringGreen(0, 250, 154);
    Color Color::MediumTurquoise(72, 209, 204);
    Color Color::MediumVioletRed(199, 21, 133);
    Color Color::MidnightBlue(25, 25, 112);
    Color Color::MintCream(245, 255, 250);
    Color Color::MistyRose(255, 228, 225);
    Color Color::Moccasin(255, 228, 181);
    Color Color::NavajoWhite(255, 222, 173);
    Color Color::Navy(0, 0, 128);
    Color Color::OldLace(253, 245, 230);
    Color Color::Olive(128, 128, 0);
    Color Color::OliveDrab(107, 142, 35);
    Color Color::Orange(255, 165, 0);
    Color Color::OrangeRed(255, 69, 0);
    Color Color::Orchid(218, 112, 214);
    Color Color::PaleGoldenrod(238, 232, 170);
    Color Color::PaleGreen(152, 251, 152);
    Color Color::PaleTurquoise(175, 238, 238);
    Color Color::PaleVioletRed(219, 112, 147);
    Color Color::PapayaWhip(255, 239, 213);
    Color Color::PeachPuff(255, 218, 185);
    Color Color::Peru(205, 133, 63);
    Color Color::Pink(255, 192, 203);
    Color Color::Plum(221, 160, 221);
    Color Color::PowderBlue(176, 224, 230);
    Color Color::Purple(128, 0, 128);
    Color Color::RebeccaPurple(102, 51, 153);
    Color Color::Red(255, 0, 0);
    Color Color::RosyBrown(188, 143, 143);
    Color Color::RoyalBlue(65, 105, 225);
    Color Color::SaddleBrown(139, 69, 19);
    Color Color::Salmon(250, 128, 114);
    Color Color::SandyBrown(244, 164, 96);
    Color Color::SeaGreen(46, 139, 87);
    Color Color::SeaShell(255, 245, 238);
    Color Color::Sienna(160, 82, 45);
    Color Color::Silver(192, 192, 192);
    Color Color::SkyBlue(135, 206, 235);
    Color Color::SlateBlue(106, 90, 205);
    Color Color::SlateGray(112, 128, 144);
    Color Color::Snow(255, 250, 250);
    Color Color::SpringGreen(0, 255, 127);
    Color Color::SteelBlue(70, 130, 180);
    Color Color::Tan(210, 180, 140);
    Color Color::Teal(0, 128, 128);
    Color Color::Thistle(216, 191, 216);
    Color Color::Tomato(255, 99, 71);
    Color Color::Turquoise(64, 224, 208);
    Color Color::Violet(238, 130, 238);
    Color Color::Wheat(245, 222, 179);
    Color Color::White(255, 255, 255);
    Color Color::WhiteSmoke(245, 245, 245);
    Color Color::Yellow(255, 255, 0);
    Color Color::YellowGreen(154, 205, 50);

    static std::unordered_map<std::string, Color> ColorNames = { { "aliceblue", Color::AliceBlue },
        { "antiquewhite", Color::AntiqueWhite }, { "aqua", Color::Aqua },
        { "aquamarine", Color::Aquamarine }, { "azure", Color::Azure }, { "beige", Color::Beige },
        { "bisque", Color::Bisque }, { "black", Color::Black },
        { "blanchedalmond", Color::BlanchedAlmond }, { "blue", Color::Blue },
        { "blueviolet", Color::BlueViolet }, { "brown", Color::Brown },
        { "burlywood", Color::BurlyWood }, { "cadetblue", Color::CadetBlue },
        { "chartreuse", Color::Chartreuse }, { "chocolate", Color::Chocolate },
        { "coral", Color::Coral }, { "cornflowerblue", Color::CornflowerBlue },
        { "cornsilk", Color::Cornsilk }, { "crimson", Color::Crimson }, { "cyan", Color::Cyan },
        { "darkblue", Color::DarkBlue }, { "darkcyan", Color::DarkCyan },
        { "darkgoldenrod", Color::DarkGoldenrod }, { "darkgray", Color::DarkGray },
        { "darkgreen", Color::DarkGreen }, { "darkkhaki", Color::DarkKhaki },
        { "darkmagenta", Color::DarkMagenta }, { "darkolivegreen", Color::DarkOliveGreen },
        { "darkorange", Color::DarkOrange }, { "darkorchid", Color::DarkOrchid },
        { "darkred", Color::DarkRed }, { "darksalmon", Color::DarkSalmon },
        { "darkseagreen", Color::DarkSeaGreen }, { "darkslateblue", Color::DarkSlateBlue },
        { "darkslategray", Color::DarkSlateGray }, { "darkturquoise", Color::DarkTurquoise },
        { "darkviolet", Color::DarkViolet }, { "deeppink", Color::DeepPink },
        { "deepskyblue", Color::DeepSkyBlue }, { "dimgray", Color::DimGray },
        { "dodgerblue", Color::DodgerBlue }, { "firebrick", Color::FireBrick },
        { "floralwhite", Color::FloralWhite }, { "forestgreen", Color::ForestGreen },
        { "fuchsia", Color::Fuchsia }, { "gainsboro", Color::Gainsboro },
        { "ghostwhite", Color::GhostWhite }, { "gold", Color::Gold },
        { "goldenrod", Color::Goldenrod }, { "gray", Color::Gray }, { "green", Color::Green },
        { "greenyellow", Color::GreenYellow }, { "honeydew", Color::HoneyDew },
        { "hotpink", Color::HotPink }, { "indianred", Color::IndianRed },
        { "indigo", Color::Indigo }, { "ivory", Color::Ivory }, { "khaki", Color::Khaki },
        { "lavender", Color::Lavender }, { "lavenderblush", Color::LavenderBlush },
        { "lawngreen", Color::LawnGreen }, { "lemonchiffon", Color::LemonChiffon },
        { "lightblue", Color::LightBlue }, { "lightcoral", Color::LightCoral },
        { "lightcyan", Color::LightCyan }, { "lightgoldenrodyellow", Color::LightGoldenrodYellow },
        { "lightgray", Color::LightGray }, { "lightgreen", Color::LightGreen },
        { "lightpink", Color::LightPink }, { "lightsalmon", Color::LightSalmon },
        { "lightsalmon", Color::LightSalmon }, { "lightseagreen", Color::LightSeaGreen },
        { "lightskyblue", Color::LightSkyBlue }, { "lightslategray", Color::LightSlateGray },
        { "lightsteelblue", Color::LightSteelBlue }, { "lightyellow", Color::LightYellow },
        { "lime", Color::Lime }, { "limegreen", Color::LimeGreen }, { "linen", Color::Linen },
        { "magenta", Color::Magenta }, { "maroon", Color::Maroon },
        { "mediumaquamarine", Color::MediumAquamarine }, { "mediumblue", Color::MediumBlue },
        { "mediumorchid", Color::MediumOrchid }, { "mediumpurple", Color::MediumPurple },
        { "mediumseagreen", Color::MediumSeaGreen }, { "mediumslateblue", Color::MediumSlateBlue },
        { "mediumslateblue", Color::MediumSlateBlue },
        { "mediumspringgreen", Color::MediumSpringGreen },
        { "mediumturquoise", Color::MediumTurquoise },
        { "mediumvioletred", Color::MediumVioletRed }, { "midnightblue", Color::MidnightBlue },
        { "mintcream", Color::MintCream }, { "mistyrose", Color::MistyRose },
        { "moccasin", Color::Moccasin }, { "navajowhite", Color::NavajoWhite },
        { "navy", Color::Navy }, { "oldlace", Color::OldLace }, { "olive", Color::Olive },
        { "olivedrab", Color::OliveDrab }, { "orange", Color::Orange },
        { "orangered", Color::OrangeRed }, { "orchid", Color::Orchid },
        { "palegoldenrod", Color::PaleGoldenrod }, { "palegreen", Color::PaleGreen },
        { "paleturquoise", Color::PaleTurquoise }, { "palevioletred", Color::PaleVioletRed },
        { "papayawhip", Color::PapayaWhip }, { "peachpuff", Color::PeachPuff },
        { "peru", Color::Peru }, { "pink", Color::Pink }, { "plum", Color::Plum },
        { "powderblue", Color::PowderBlue }, { "purple", Color::Purple },
        { "rebeccapurple", Color::RebeccaPurple }, { "red", Color::Red },
        { "rosybrown", Color::RosyBrown }, { "royalblue", Color::RoyalBlue },
        { "saddlebrown", Color::SaddleBrown }, { "salmon", Color::Salmon },
        { "sandybrown", Color::SandyBrown }, { "seagreen", Color::SeaGreen },
        { "seashell", Color::SeaShell }, { "sienna", Color::Sienna }, { "silver", Color::Silver },
        { "skyblue", Color::SkyBlue }, { "slateblue", Color::SlateBlue },
        { "slategray", Color::SlateGray }, { "snow", Color::Snow },
        { "springgreen", Color::SpringGreen }, { "steelblue", Color::SteelBlue },
        { "tan", Color::Tan }, { "teal", Color::Teal }, { "thistle", Color::Thistle },
        { "tomato", Color::Tomato }, { "turquoise", Color::Turquoise }, { "violet", Color::Violet },
        { "wheat", Color::Wheat }, { "white", Color::White }, { "whitesmoke", Color::WhiteSmoke },
        { "yellow", Color::Yellow }, { "yellowgreen", Color::YellowGreen } };

    Color::Color()
        : m_type(ColorType::Rgba)
    {
    }

    Color::Color(const double r, const double g, const double b, const double a)
        : m_type(ColorType::Rgba)
    {
        this->from_rgb(r, g, b, a);
    }

    Color::Color(const std::string& name_or_hex)
    {
        this->from_string(name_or_hex);
    }

    Color::Color(const sf::Color& color)
        : m_type(ColorType::Rgba)
    {
        this->r = color.r;
        this->g = color.g;
        this->b = color.b;
        this->a = color.a;
    }

    vili::node Color::schema() const
    {
        return vili::object {};
    }

    vili::node Color::dump(ColorType type) const
    {
        vili::node result;
        if (type == ColorType::Hex)
        {
            result = to_hex();
        }
        else if (type == ColorType::Hsv)
        {
            Hsv value = to_hsv();
            result = vili::object {
                { "H", value.H },
                { "S", value.S },
                { "V", value.V },
            };
        }
        else if (type == ColorType::ColorName)
        {
            result = to_string();
        }
        else
        {
            result = vili::object {
                { "r", r },
                { "g", g },
                { "b", b },
                { "a", a },
            };
        }
        return result;
    }

    vili::node Color::dump() const
    {
        return dump(m_type);
    }

    void Color::load(const vili::node& data)
    {
        if (data.is<vili::object>() && data.contains("r"))
        {
            const double r = data.at("r").as<vili::number>();
            const double g = data.at("g").as<vili::number>();
            const double b = data.at("b").as<vili::number>();
            const double a = data.contains("a") ? data.at("a").as<vili::number>() : 255.f;
            this->from_rgb(r, g, b, a);
        }
        else if (data.is<vili::object>() && data.contains("H"))
        {
            const double H = data.at("H").as<vili::number>();
            const double S = data.at("S").as<vili::number>();
            const double V = data.at("V").as<vili::number>();
            this->from_hsv(H, S, V);
        }
        else if (data.is<vili::string>())
        {
            this->from_string(data);
        }
        else
        {
            throw exceptions::InvalidSpriteColorType(
                vili::to_string(data.type()), data.dump(), EXC_INFO);
        }
    }

    void Color::from_string(std::string string)
    {
        if (!this->from_name(string, false))
        {
            this->from_hex(string);
        }
    }

    bool Color::from_name(std::string name, bool strict)
    {
        std::for_each(name.begin(), name.end(), [](char& c) { c = std::tolower(c); });
        if (const auto& color = ColorNames.find(name); color != ColorNames.end())
        {
            this->r = color->second.r;
            this->g = color->second.g;
            this->b = color->second.b;
            this->a = color->second.a;
            m_type = ColorType::ColorName;
            return true;
        }
        if (!strict)
            return false;
        throw exceptions::InvalidColorName(name, EXC_INFO);
    }

    void Color::from_rgb(const double r, const double g, const double b, const double a)
    {
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || a < 0 || a > 255)
        {
            throw exceptions::InvalidRgbFormat(r, g, b, a, EXC_INFO);
        }
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
        m_type = ColorType::Rgba;
    }

    void Color::from_hsv(const double H, const double S, const double V)
    {

        if (H < 0 || H > 360 || S < 0.0 || S > 1.0 || V < 0.0 || V > 1.0)
        {
            throw exceptions::InvalidHsvFormat(H, S, V, EXC_INFO);
        }

        const double C = S * V;
        const double X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
        const double m = V - C;
        double Rs, Gs, Bs;

        if (H >= 0 && H < 60)
        {
            Rs = C;
            Gs = X;
            Bs = 0;
        }
        else if (H >= 60 && H < 120)
        {
            Rs = X;
            Gs = C;
            Bs = 0;
        }
        else if (H >= 120 && H < 180)
        {
            Rs = 0;
            Gs = C;
            Bs = X;
        }
        else if (H >= 180 && H < 240)
        {
            Rs = 0;
            Gs = X;
            Bs = C;
        }
        else if (H >= 240 && H < 300)
        {
            Rs = X;
            Gs = 0;
            Bs = C;
        }
        else
        {
            Rs = C;
            Gs = 0;
            Bs = X;
        }

        this->r = (Rs + m) * 255;
        this->g = (Gs + m) * 255;
        this->b = (Bs + m) * 255;
        m_type = ColorType::Hsv;
    }

    uint32_t Color::to_integer() const
    {
        return (std::lround(r) << 24) + (std::lround(g) << 16) + (std::lround(b) << 8)
            + std::lround(a);
    }

    void Color::from_hex(std::string hex_code)
    {
        std::array<unsigned short, 4> rgba { 0, 0, 0, 255 };
        std::stringstream ss;
        std::string str;

        if (hex_code[0] == '#')
        {
            hex_code.erase(0, 1);
        }

        const int size = hex_code.size();

        if (size != 3 && size != 4 && size != 6 && size != 8
            || hex_code.find_first_not_of("AaBbCcDdEeFf0123456789") != std::string::npos)
        {
            throw exceptions::InvalidHexFormat(hex_code, EXC_INFO);
        }

        for (unsigned int i = 0; i < (3 + (size % 3 ? 1 : 0)); i++)
        {
            if (size == 3 || size == 4)
            {
                str = std::string(2, hex_code[i]);
            }
            else if (size == 6 || size == 8)
            {
                str = hex_code.substr(i * 2, 2);
            }
            else
            {
                break;
            }
            ss << std::hex << str;
            ss >> rgba[i];
            ss.clear();
        }

        this->r = rgba[0];
        this->g = rgba[1];
        this->b = rgba[2];
        this->a = rgba[3];
        m_type = ColorType::Hex;
    }

    Hsv Color::to_hsv() const
    {
        Hsv result;

        double Rs = r / 255;
        double Gs = g / 255;
        double Bs = b / 255;

        double min = Rs < Gs ? Rs : Gs;
        min = min < Bs ? min : Bs;

        double max = Rs > Gs ? Rs : Gs;
        max = max > Bs ? max : Bs;

        result.V = max;
        double delta = max - min;
        if (delta < 0.003)
        {
            result.S = 0;
            result.H = 0;
            return result;
        }
        if (max > 0.0)
        {
            result.S = (delta / max);
        }
        else
        {
            result.S = 0.0;
            result.H = 0;
            return result;
        }
        if (Rs >= max)
        {
            result.H = (Gs - Bs) / delta;
        }
        else if (Gs >= max)
        {
            result.H = 2.0 + (Bs - Rs) / delta;
        }
        else
        {
            result.H = 4.0 + (Rs - Gs) / delta;
        }

        result.H *= 60.0;

        if (result.H < 0.0)
            result.H += 360.0;
        return result;
    }

    std::optional<std::string> Color::to_name() const
    {
        auto it = std::find_if(ColorNames.begin(), ColorNames.end(),
            [this](const std::pair<std::string, Color>& color) { return color.second == *this; });
        if (it != ColorNames.end())
        {
            return it->first;
        }
        return std::nullopt;
    }

    std::string Color::to_hex() const
    {
        std::stringstream ss;
        ss << "#";
        ss << std::hex << (std::lround(r) << 16 | std::lround(g) << 8 | std::lround(b));
        if (std::lround(a) != 255)
        {
            ss << std::hex << std::lround(a);
        }
        return ss.str();
    }

    std::string Color::to_string() const
    {
        const std::optional<std::string> name = to_name();
        return name.value_or(to_hex());
    }

    bool Color::operator==(const Color& color) const
    {
        return to_integer() == color.to_integer();
    }

    bool Color::operator!=(const Color& color) const
    {
        return to_integer() != color.to_integer();
    }

    Color Color::operator+(const Color& color) const
    {

        return Color(r + color.r, g + color.g, b + color.b, a + color.a);
    }

    void Color::operator+=(const Color& color)
    {

        r += color.r;
        g += color.g;
        b += color.b;
        a += color.a;
    }

    Color Color::operator-(const Color& color) const
    {

        return Color(r - color.r, g - color.g, b - color.b, a - color.a);
    }

    void Color::operator-=(const Color& color)
    {

        r -= color.r;
        g -= color.g;
        b -= color.b;
        a -= color.a;
    }

    Color Color::operator*(const Color& color) const
    {

        return Color(r * color.r, g * color.g, b * color.b, a * color.a);
    }

    Color Color::operator*(double value) const
    {

        return Color(r * value, g * value, b * value, a * value);
    }

    void Color::operator*=(const Color& color)
    {

        r = r * color.r;
        g = g * color.g;
        b = b * color.b;
        a = a * color.a;
    }

    void Color::operator*=(double value)
    {

        r = r * value;
        g = g * value;
        b = b * value;
        a = a * value;
    }

    Color Color::operator/(const Color& color) const
    {

        return Color(r / color.r, g / color.g, b / color.b, a / color.a);
    }

    Color Color::operator/(double value) const
    {

        return Color(r / value, g / value, b / value, a / value);
    }

    void Color::operator/=(const Color& color)
    {

        r = r / color.r;
        g = g / color.g;
        b = b / color.b;
        a = a / color.a;
    }

    void Color::operator/=(double value)
    {

        if (value != 0)
        {
            r = r / value;
            g = g / value;
            b = b / value;
            a = a / value;
        }
        else
        {
            r = 255;
            g = 255;
            b = 255;
            a = 255;
        }
    };

    Color Color::operator-() const
    {

        return Color(255 - r, 255 - g, 255 - b, 255 - a);
    }

    Color::operator sf::Color() const
    {
        return sf::Color(r, g, b, a);
    }

    Color Color::Random(bool random_alpha)
    {
        int alpha = 255;
        if (random_alpha)
        {
            alpha = utils::math::randint(0, 255);
        }
        const int r = utils::math::randint(0, 255);
        const int g = utils::math::randint(0, 255);
        const int b = utils::math::randint(0, 255);
        return Color(r, g, b, alpha);
    }

    std::ostream& operator<<(std::ostream& os, const Color& color)
    {
        os << "Color(" << std::lround(color.r) << ", " << std::lround(color.g) << ", "
           << std::lround(color.b) << ", " << std::lround(color.a) << ")";
        return os;
    }
} // namespace obe::graphics
