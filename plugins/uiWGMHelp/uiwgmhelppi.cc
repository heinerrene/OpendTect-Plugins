#include "odplugin.h"
#include "uimsg.h"
#include "uihelpview.h"
#include "uiwgmhelpmod.h"
#include "wmplugins.h"

typedef struct keyholder {
    const char* key;
    const char* link;
} keyholder;

keyholder keys[] = {
    {"avo", "AVOAttrib.html"},
    {"avop","AVOPolarAttrib.html"},
    {"deh", "DataExtentHorizon.html"},
    {"ext", "ExternalAttrib.html"},
    {"geopkg", "GeopackageExport.html"},
    {"geotiff", "GeotiffExport.html"},
    {"grad", "GradientAttrib.html"},
    {"grid2d3d","Grid2D-3D.html"},
    {"ltf", "LTFAttrib.html"},
    {"mistie", "Mistie.html"},
    {"mlv", "MLVFilter.html"},
    {"rspec","RSpecAttrib.html"},
    { 0, 0}
};

class WGMHelpProvider : public SimpleHelpProvider
{
public:
    WGMHelpProvider( const char* baseurl )
    : SimpleHelpProvider(baseurl)
    {}
    
    static void initClass()
    {
        HelpProvider::factory().addCreator( WGMHelpProvider::createInstance, "wgm");
    }
    
    static HelpProvider* createInstance()
    {
        BufferString baseurl( "http://waynegm.github.io/OpendTect-Plugin-Docs/plugins/" );
        WGMHelpProvider* hp = new WGMHelpProvider( baseurl.buf());
        int idx = 0;
        while (keys[idx].key) {
            hp->addKeyLink( keys[idx].key, keys[idx].link );
            idx++;
        }
        return hp;
    }
};

mDefODPluginInfo(uiWGMHelp)
{
    mDefineStaticLocalObject( PluginInfo, retpi,(
	"uiWGMHelp plugin",
	wmPlugins::sKeyWMPlugins(),
	wmPlugins::sKeyWMPluginsAuthor(),
	wmPlugins::sKeyWMPluginsVersion(),
	"Help provider for the WMPlugin's collection.") );
    return &retpi;
}

mDefODInitPlugin(uiWGMHelp)
{
    WGMHelpProvider::initClass();
    return 0;
}
