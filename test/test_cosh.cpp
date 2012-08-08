///////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2002 - 2011.
//  Copyright 2011 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_
//
// This work is based on an earlier work:
// "Algorithm 910: A Portable C++ Multiple-Precision System for Special-Function Calculations",
// in ACM TOMS, {VOL 37, ISSUE 4, (February 2011)} (C) ACM, 2011. http://doi.acm.org/10.1145/1916461.1916469

#ifdef _MSC_VER
#  define _SCL_SECURE_NO_WARNINGS
#endif

#include <boost/detail/lightweight_test.hpp>
#include <boost/array.hpp>
#include "test.hpp"

#if !defined(TEST_MPF_50) && !defined(TEST_MPF) && !defined(TEST_BACKEND) && !defined(TEST_MPZ) && !defined(TEST_CPP_DEC_FLOAT) && !defined(TEST_MPFR) && !defined(TEST_MPFR_50) && !defined(TEST_MPQ)
#  define TEST_MPF_50
//#  define TEST_MPF
#  define TEST_BACKEND
#  define TEST_CPP_DEC_FLOAT

#ifdef _MSC_VER
#pragma message("CAUTION!!: No backend type specified so testing everything.... this will take some time!!")
#endif
#ifdef __GNUC__
#pragma warning "CAUTION!!: No backend type specified so testing everything.... this will take some time!!"
#endif

#endif

#if defined(TEST_MPF_50)
#include <boost/multiprecision/gmp.hpp>
#endif
#if defined(TEST_MPFR_50)
#include <boost/multiprecision/mpfr.hpp>
#endif
#ifdef TEST_BACKEND
#include <boost/multiprecision/concepts/mp_number_archetypes.hpp>
#endif
#ifdef TEST_CPP_DEC_FLOAT
#include <boost/multiprecision/cpp_dec_float.hpp>
#endif

template <class T>
void test()
{
   static const boost::array<const char*, 51u> data =
   {{
           "1.0560191127459844751259038114395241283965590525302917878166464679729562764239266483419824023679041866569431842053263976225991679105269492268050148624443706785607467750929028856273183654547152707568642275917435773104050171284580773949313906303074811586096214771879801872225500237540725592288167903987152007171391207680034517664218965133028298959753155835975555361514087618679892905973726581183754237665",
           "6.0577917650974496023981039346694689204850927958941226507775366589415588030232830758139222010716099059155799853188868489737439396141346120898610181630988217093945337280471788812956307352429914669334599644412036010014302812555700905490062030666482387008384856645533100266205122930455496234252478878949675888122615795451076521244771554025667181070733415815608287241160724578541982548132473721865287585003",
           "383.32956577005424506758441449272199796616394738942294350035763341369127219359132618750028176886177362785452836065735889720098699937365992620246167965376788963171659530350198190156275836547285437366012371175910490835823389352716981464503672749829183569550509561579181434088407652213421105693358960196044447948190823567291153397039759820680087749250557665869797605969680417240900163183563482342795870741",
           "180470.88335034971169904627554690213669106779370247753503772451628313223853228134148123711258586005038324156900626143047383382773083164188515409766952843294484598668304799186411411329575367546332731190431166613267871177008493921416649792646568096789971466064344922873643120446759328638447781504932928745974584136039698220604099816877847080168890581112550484205291341188894903342677757367415636409890558",
           "6.2781497954189513287619297175142770025826052476955600323495790530946900406209789437212923381830889846578651793922971071825731424267985994598149826652782605981764572599129753631344305259620294513472869937699509893247230674850025066547664563263958672029867981296029855675095947587305949634130736118694040608573981560192569935477462121110619100122692626135788198431038121227062383110684489973794745342204e8",
           "1.613783114750852113223226710244634574082654363427931747177970610142560035434819323665197978270795707611590961019502906079030261920109649748962125930850198625621792763842224096823299250338750953491004408731082880660125641628213970297576817341593254767125933119462446651783267917469179893016103516988279473907996009458208097272806046395206212403180775656514566222835047724943633607736647735739948551096e13",
           "3.0651210048650948869531196671342477415226643123350617715268971834881834615138925908518703584506447138436613632341330640449725016173384960626760387649747643297918807083363913015806893683786389067836005832038060734248371426886808175554210317756018846109627572546314172492701544345965940408777570519312837860014177872754358662463423939942202520475422342889660750666147940146262635303938752019875745307992e18",
           "4.3016893602106215864771434464025735547192956887050537014696231526954713331351791376069506688795159316625154458115179050297716224800318064110052445970764898870599885508391064218065806885129697936678362276766771902589638957537168339190488273555753876162633237990462617955892238424402124353124736879474651977422350856642986446591941163073842974714357745162365700428610167249762162775568692443158879770006e24",
           "4.4608685929681360001024935791890661655506049487122331222491789277138083092507844933483858468341107613657448783043064935174812965310544903547535217357996429824403225005261842368679242972243707736489629610256554995236901040773902962370130989883960298987808008001651650799892267761089302132749037069497452309074389846493140222931714618697738906019885122076310868220596765753447232222740129365498326869428e31",
           "3.4181315955816806472569357441100390029536003312981931954091744304974491527743601285017456624487264929971022746516079644284683284072159616291298593217459064246713801084801182706805865477209408120733740982340972570739267039630582468876075574706187115643861449939429503730606743466086010115127464706315791765264572070452800816054590653675962889901898843712936126341807733200610910325052666512334161414655e39",
           "1.935294628272790810141453021278524976364077691905248015888165919062516673344977091262644262832934899971824373171672037249361491844419302323587942915162859665992916625636813244576210109931852761921719987632855596663907494303248513195744818730879742963301327852160193919379798462926667740594397712731448572837824802330973561570848397758210619453310032286208701226098998940360395267237151018055781640126e48",
           "8.0964449511890098565841496436016431651692307764702784234901741408135381374668439020986470675941110923614446905696411023621632714191313583360826598468217983223558130595633054971338824192327248896500337050246640453410159732184419096917171044075711156867804851018388576371530520943696439917673720450911725466781235347212700849702742625663288687644090935756560022610000629006347244369388824818661974220426e57",
           "2.5028257092625174549175008952222569141816383637904981644379473858250736896174216539673733521627607209322019413420937570273676341726636307131078699799472622998437404149614292337267153201903296102921815263736653035269935857816159086496594269187082442244280898258397047045746728729079796167987895368614037770286371191530575814695859433478185016171380286325273493350193132538052551497175771289873181595171e68",
           "5.7168370213792649967466315312864179662895170192695050789061362839510836418124645968032989149068311018994324517420345278843446068634292140996241291031113395887832891095928020095581695527354104986223411349657526888924224926675682032043363279774947976053895819671003276400297758359779703605970507328706064692923481168676751999124073697599262277247814864401196929320497117521176016017349797292609303756215e79",
           "9.6487261169670031207955841899729386502708125098394777808615183927342163909284025992243201020435915122698808649711566042372911206942311277943247994427354130507790526857797833309691667380623792736661655695464087154725768656507603378053220212067894914686147301550764045337512361478831034999674296837635744344039906734109560908793921568633128400104314078575159786136202769893309913175064586488844295321363e91",
           "1.2032977660238608232537005158851668311089986235965463249220377778638489972355974848209035082333822309902237165042868213438627625544096344578102199846440476859557339736747791529782018329078191477783605471526120466881600981869890379917878811691555316448842731085218988710571211956972016424649758226606500603194972966032036214213759991156778846329137084961334557845326183588274571457361004704490747798678e105",
           "1.1088306081278288754492401130897590262404571813281460605683836139669281218442501421935533170636990866165181664561596333701204545493730707210930818738817252706131805203538144119244917164949716209095542194899833868499263375700313934257155601275526921302332118009966650991624878227108265079219497366770219141098050965023005919495048022616553249266192057652205987267068584616625670961423579715954410508985e119",
           "7.5499880591625965663868042832675300901799245732418501707646792135512053284835138294796976048691668315442427834949618514094329533376442442492757936744857569785450769927581802961191319878260712808001736830227501518832554201816224207300614310712430470538022948957433004829725273067921443635526965673971412049693552004259820173389681647135125678701502084190660111860351299407405357314966388044340723077086e133",
           "3.7985363580067976240250330165300706958269826851549371732460220923459822809007918495780412109700378352703982899561570150646963751463572075768540297484136809462018052149545042828665345287117150392150513078663739946623681053685054650372595872914400423446635806806461783139586204378680585507446218544068845246753010850565341852111017728985713047360191412931479535524815646071456825031827933342626130249175e149",
           "1.4121319341572581270215359848706630542776633675711529687593487346259283960708095601494823112486631023721124235640943167173029348028743563902367757599140008654691320430919753414890689949599421028277624880392344132646738394546195638261279687543208503932172926275294218429086816560213399180179494004109164546844899632385177835442946174689070525154077366030192931540897742543089509897490703511310531249977e166",
           "3.8790307719997974510664339744260233373881096199933152202662556556779783775106563986911859526413282055258612522499767709123313205863879946518297779104337686883587019222829967005608205535314284003183828513113021722123872387036435113517356676447376715595408179555267871947671679098986651665719279348025058713817796876795915844151719103197410787508530261619841035613531488383930867055908047961915279983259e183",
           "7.8733605373835840397434523264038598405672829925651165847065668324385430746087633348848905637835428739401439679896923081980364912472282573695612463537585283007941057172128277340402716645674443632827653710173742423648839359547777694778576675604645880219833375227941998426325886558435214355022240854563558864080627758653439429917072753785194675103766900514602432580639079224631229479607396935864512990879e201",
           "1.1808262995038900942517891457926200063018079695348469762725520377876370005771518954251015338402886097689762895044056273430051256244413916763438966705458118354189107806216991150264176024521937328179762640422127608560103802431672144866013216405157197709788484197720057702118788168789816074560208078260433548283881535909071116553897893659656781376448427981358955547508806938614921874867135186509274509121e221",
           "1.3085817499987842655130548827168955655838432140245228169691892267707778790498773914833199368916114043966197329562444577848635313938483757629541576533880917215885485474416704968999200090496252044959849927443732134176975867869986011315975625868009065373046224716063168977788103866885720471095547385342868632018951910603936835789387464412366605713487321530237148912677199033012777178113821791621549557963e241",
           "1.0715308148006899161903881353829644069217121138682658034413051575604561649576261428568888094218620444635013220705511245290719605273316790249367622122178650529000528086055415007045458486410501636380119413632657994999412652188430063128470336817401482172580366374079331295129200936246446347832380606353293858222758687479612927181530236387227215663399410099251455256898414199913458340065553949424990477448e262",
           "6.483319651006309502237640505955012384293570932602353784849377890534620180296272226076424490097577093511886503973590409376477611667988893542117173598716788837179265384921201772013611631892729250835822804494742316330406688475091973437669111728949960922002370308207819760146543720499389938855072810566961589413895110830251224194598788696990065693705615156654866578134664648091752361824241438921952031149e283",
           "2.8985391304542768293172709775230767981477721528885408305355619530690119426207269563049756824939397157221877775531212262059946098575425050827283362457005503261796116156917077778477251551070762614233325253060283603452216492681531839154649232080928787066338399915850327381614672456102374248950210248266796072457623370079195574322846594267768883120374288952014885152055438195794090975578878933873824774214e306",
           "9.57524433627083921372674145950563946532138741951042299439035158875449060589509856903496678820625880407684156184675763001790613289835869844325821965070261880894138207436003366195024403902162467929095155787852409710735775347490909311196315332711680552044467458169615366116872469435840608534489425322247278926672059747911266981024366989976214521515026692183039600169984107883592297128416659318858313127e329",
           "2.3372734503362369375381009524197350830316472034721759761797536237738670471009423543542251572488229045699598160834162677357730620072441755506075897500940629883044875771104686291523502165266242030847074909362622098365719455332359938746138629161304717385265309980898079489959955157644566232440805137701071311495653330606071611331941246434767948905863368638163788562679785940566685500460815077065003612487e354",
           "4.2155879126937199240969909448599186868484717887298729605150033299123534992857332918168135230843738695925698383815575417820480732378749635394939513838137876524333991937836847074991505476867647762082587225838063325020413513077128321581439429001485977751765798011101092072613053687422983352140468569171564773941232256057064161142341661775359191159220450305300322654184921617310753474842253496677498824723e379",
           "5.6181811613375701248970224378256740494692066242437602652469740512738297599235414593999616891945156186827736326184687322137498447792007445397397290336810468925670064733464757082986791232916898141597610692740388799796632396708149027243436859752526805112778790645096555770227809873695589969805678601106157556386974221647669590827712353133603091803570183764883405340587430017053183637835511899658145649708e405",
           "5.532511069282205350923830187073466127274584467195468607886763750877294392993663821432158885753563495238131394373865428654052604326264330104646257659760161386620716716703631608643312613245804625511813964275109451513736558514977338129201153666764317441936156609643185133981728847167450887861106642311329612564652645663234240748195490808151911497393974690166034839217817023634217121406163178148652748479e432",
           "4.0256666306761331240653217136731531623017017695713942917027851762705346357330788586411431378972009980532310757689380174461664677676028378924382554201434975574729861177781849023768222381429947872325368088023224591306630434887529215459580760863075907686248521168590309636468448648513752893851767315693469638980874648457114335557202115472595647478331668869318302753802858726588719006447471192697846325955e460",
           "2.1644237346681663424601781769159797919834245365230735589058796985974745594485988855971413936820871935714602237643458356241187573307428309041919648027960168541647193436225977495680484218384107820095589356463058222584008532497069179993678533431131233629312850771528970443634604290143149079209513868130585713006080733488491160321145735562062411305931183571279530201672366980412430529846635995189699318073e489",
           "8.5987580981195983662047247216936066485731760315371506386077056691409579856014763032619539539935299716110411688793466397984311640631361934500807639285587334983206556915704635831992012926186843826981296831658998834850783404713050829093753126189556625095994621605300047199962332098857236359801681157419606676412198783092816364336047306243999363335004760439115355072350465422891365411868472688286678516314e518",
           "2.5241673163187127276134610716954724162270290228773641734420864618245211926017624829840685860130579257772126398622324109858115624706486522844752512951837805396709793171502497523431473021570806024043139443284538862368635312799539108264084028032731295487282188616820261689634926427135060887942797635147693849950058672753458576476491733064455826768562371858057444914175251596852571637211466017938478085247e549",
           "5.475067911823387661325942057081957044927796274441278042805014835144678321092623034147031518807063234976073102574257079170283458172046752719724152941316842521196069804425876507927418423409523739261726681120662097159943049401039490818332686968135012747332468921142470970507219403290422458185430415836291605355383658657658638112408092789126678938878667507151950931633694006471359998448912249374833586727e580",
           "8.7750549689950256776639468724574158629603320014390275681028674550826357080136422399476213432791376656222763800628593282303459051561266270006921840049305819767639184391149913915312831894296821356222752594264134130151457242713539248421883837353442181724530706933220158507240760325182068001553294949268596178418634164323874971937997072367419479635154591248667559627811893588163238012665671798461211917208e612",
           "1.0392000158337773273751156576416024664653679689973856373456304843339302977923254238376497044027728158058903302390909588333829463843362779584402914847447592731182614369968957680281500946805571235013941407979569788567794900810257154433592958167545186687137810101848000107335074486050959387974516414654638879740966175786016492797845169374594168995878543584318334800124941205910589727264397237600733483158e646",
           "9.0936326753636727240574546678839170665019169110943878894933093211555976995701468041449327370073681898690638466136204694745206283652338526673125958055131610409923286526192661778126811265116493171283319361595267283588121098349703951929669281966675596890266483864217591555707552765565756842701056144290075867893520379419521775913047964393758374891516340929062076304350159966063972713118995033247759001609e679",
           "5.8798281636930489964162009429009257867906792508058801627042121953599912951265315933723440185825519080102988056836911095299854840387008575164090793635997912930561430335216151607097220208013034399895832350235280120270626904356196935166701773768680311063264380891331021514518757839220818506905997847228783439015252768055166165941582030353226255576433910936297965207260585437762430381969160714956727596198e714",
           "2.8091881292911108404345975896815558958477835260737794579417284512413473388968057587088555041266297486841923628702282019643659456724373332519583025947015025975126598748630623031951723754960589046233996595466021913942587558326660593063197905288573353559106884645285531497626940379800500474282446929237914568534665868703742731713632349090897884403966643055728471509474896855575286123275564417626861566706e750",
           "9.917129372597671132067673866739246238179742417231064062960232866725337575281938597212073697168000155027158148165861617400080837699968785505107579831803685516054837447325150388867488754170677228096524224392410232206238263933144338637103531441623303187445874039234973380151391274490746625993568552049954630793219419614845431626975962881182662815760423226111647056071831411664335144052772436215105801395e786",
           "2.5869027163543111121878679987081647715187872826677398475096738640583659800068967379551376322170347537454918190603891312949716382621902484616361664158953484778255247083652726854621059785392022847887382779010079407502679229021085320675903109573769331277413372272363218896397965662581357886739691376204316908974081821980432178065394228926767529685562155837452626029223937027004015040825450642409597700449e824",
           "4.9861251931207080923785686798881789193813879610842675205361210155894774686328710893906543682447029206928934967525495260314937837003448878215156341411477636831113484416124080974502217578408248150338565305116223944900839866528622960352723938548713319425798453345402992146078868053263606234074443024155243450623634720912438841022969909473424559262711669905282193529250216454066716533180418518228387188393e862",
           "7.1012569014339068241101751233953234216522840280342406520909288232012799547871960723719836516359548198842749536961644100550279020276709043358260853581760590386456213180291689322352732545965831405519844109680619067101311180959399339922706596098526969148981173519865139508665631317310424178378833370605922449094745510812618563813537347841030916512147874232760564378443782164868016244561788356251308121716e901",
           "7.4730215360486642135431754747074885377840195683583018254892502245011973712084221116813364423492802080799768174534590613188275471080608467087354983850284805514875889145266688973752185071777341375422809910165581997555433091939959406569831183459872344778707098094941193489061532160249775856426569696127193453339548371679229676272663084782830276508737129506676031759345288056484158647796152349867328841634e941",
           "5.8109375364209112227579654658730977030869454388607076903639465992296616832002964138000947668837140543325908222688655359602408511410663722770167244801973012245657865182739637159804595049180263175014778215232564251739259624759589953677661356104554831551073263668188283861123521688445132164147762321111597028523130093864153999974376790494383016372210442340324038686843345053322425194077414241243050491297e982",
           "3.33875955701899627718146291382268063073604182131575843695486667154496711979350813988644889979275310892951143249901398447859083674739840084454465850475774696325142148671937407108540250845900941142800157345665761403930889797424808979569550325271558518404559007551625637761142662107757913763221912282957681784053564387104062317729788737215450574233690655931888608424916152893688106181220341997128198692e1024",
           "1.4174672877823334709610117319768830739080734407353905145632612088824955720198734996604261250019291955883620333545750761619015467840567122066622229379056280064206319780047687015558007624774062399477328822231085767309831266032616053065858739373818651687128093335640388513396191118537181280334430292439188737524362269789272308905723812818882228503013875816702686587035844437102478263525616196832018321602e1067",
           "4.4466189016791091516801723880812533528438597080549410911235655611382010503145789286158745555771483577943662768773465284793798720178177605712848440200402906836390133865748188969184005230383247111166918721449908133920663776952786683837038180436264738937354101153867171804315769471050303182129269442292354388037298125177941217926845803005587166270803697433886463469168814941555804311717400657004050157245e1110",
   }};

   T eg = "5.77215664901532860606512090082402431042159335939923598805767234884867726777664670936947063291746749514631447249807082480960504014486542836224173997644923536253500333742937337737673942792595258247094916008735203948165670853233151776611528621199501507984793745085705740029921354786146694029604325421519e-1";

   unsigned max_err = 0;
   for(unsigned k = 0; k < data.size(); k++)
   {
      const T x = eg + k;
      T val = boost::multiprecision::cosh(x * x);
      T e = relative_error(val, T(data[k]));
      unsigned err = e.template convert_to<unsigned>();
      if(err > max_err)
         max_err = err;
      val = boost::multiprecision::cosh(-x * x);
      e = relative_error(val, T(data[k]));
      err = e.template convert_to<unsigned>();
      if(err > max_err)
         max_err = err;
   }
   std::cout << "Max error was: " << max_err << std::endl;
   BOOST_TEST(max_err < 2000);
}


int main()
{
#ifdef TEST_BACKEND
   test<boost::multiprecision::number<boost::multiprecision::concepts::mp_number_backend_float_architype> >();
#endif
#ifdef TEST_MPF_50
   test<boost::multiprecision::mpf_float_50>();
   test<boost::multiprecision::mpf_float_100>();
#endif
#ifdef TEST_MPFR_50
   test<boost::multiprecision::mpfr_float_50>();
   test<boost::multiprecision::mpfr_float_100>();
#endif
#ifdef TEST_CPP_DEC_FLOAT
   test<boost::multiprecision::cpp_dec_float_50>();
   test<boost::multiprecision::cpp_dec_float_100>();
   // Some "peculiar" digit counts which stress our code:
   test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<65> > >();
   test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<64> > >();
   test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<63> > >();
   test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<62> > >();
   test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<61> > >();
   test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<60> > >();
   test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<59> > >();
   test<boost::multiprecision::number<boost::multiprecision::cpp_dec_float<58> > >();
#endif
   return boost::report_errors();
}



