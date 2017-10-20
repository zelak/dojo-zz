/**
 * 
 **/

#include <map>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using std::map;
using std::cout;
using std::endl;
using std::string;
using std::for_each;

map<char, int> countChar(const string & str)
{
    map<char, int> count;
    // count how many times a char appears
    for (auto c : str) {
        count[c] += 1;
    }

    return count;
}

map<int, char> sortByCount(const map<char, int> & in)
{
    // sort
    map<int, char> sorted;
    for(auto it = in.begin(); it != in.end(); ++it) {
        sorted[it->second] = it->first; 
    }

    return sorted;
}

string crop(const map<int, char> & in, const char delimiter)
{
    string output;
    for (auto it = in.rbegin(); it->second != delimiter; ++it) {
        output += it->second;
    }

    return output;
}


int main (int argc, char ** argv)
{
    const string input("cwrxwzbgickpjbp_svnudntddwdqbfgzyiqpuxddmpvyfquosmicfzkjekxzchngpqaksafulateukuwomdrwza_n_ptzktjzcuibnebe_tqessrzqewgkadrkvtyznaupodanwazopg_fijcoojojbsolr_ejesukzc_quochdnmti_lkvrsegyieqlqysuxdvetkqtkhxaiypfdiddztlicjurnllriopdtuuzpryrsepfydyeg_xkr_ruxp_lgqesysidfsygztwrba_ay_gaqqklbrvr_lbhawjraqujfxptmuvqfzklfodgaqrnhjravksjwemoosdlxtvw_qspxmlvqryusfixzlkb_p_c_tepzozzwnokvqspkizygoqpbhjnsxopchzgapctowbrletrunlgnvzpfwrqgedo_s_ygkxz_mpncnve_gfpbotupawevhfxvqhwlerupjfibosbvhiijrodigzyhy_iijes_xsqorshhdzkjqitpljsftpitjetwmzqiabyiewgtbjaddtsjkckcxxvlyrchloetluxkohn_uihkdjpcqgvejanslakmwendgkmvmayknvjjnr_kdapnumwvz__lsimxdtrflyleykxejl_jbkhexpcyreoapelqzzyriyrbxdgbgwrrxlj_pt_mpwubvbveakxfsbfgj___xfqilxpzalazduzucgoxz_yzhkjwamosiwclkicifmebonobknqokyevtwmekackk_kezmjkgmtgaouerwlwfkaaqhkghreoqhfjzpxrlzmbgfpvofpxkmz_cnvcvfsuokpcaimnvdxeizbbgudln__wvkrqpijlncdacmsvytdxmu_zkvzilfrymoxzlovfhdzuarqumibrcvuqfcxdcrvw_ehbwhwjoanluezhthzkpuqd_efilprbskomczdhdoyudx_sybyfuako_xmorjtdnvwlwskpxnhjhmamiyxbyhh_reqlnkbzmrn_oleixht_v_tigjuxpkmmdpxznvbeqdzuedlfywxmcrbttdp_nfzusrrvpttbtabticgdx_cdiookdmupufqhlwiidaveibsyrviqsyvgledamchipkibjftdedyxzqjgvyyrcgwopo_vmldkrzhlatforljbeeqvgonrradkgmzin_mjbareajhewvyiidczysmrmzppgiifvqecxixbtukignqzr_pzokiedmwsw_usamiqngdiolwahtkbyhob_xpvmkdvqbvywmmtogfjogumfom_ppfut_cnxnjwjeiuidnapodo_wiqvgluofjatvkwowosn_vbmdsrwkhbnmlwctcrb_ycyklnxsbhbjkpknlfsccburlfhjhteqnnwrcfonrqifiapfeqqbv_d_rgddzqkjt_eeinwww_oxropsvcpuignzzudsjugxghobkurukspjygbowcic_rmuaatueajsbdswcwnhjaoujs_nbcmmrfjqoqchrvgehdewpicqanwilpirqghzkklsfczavcegoqdflxqamzsppfozsmrmmrzjlfrbxcljdmvxeaxnifyjluwfnqdzmwzepzzxmbyev_ms_flxgevtmyiqifnrsclobraupspnpndekgyxhlkyhuaahgonahtcmhim_ufoevtvemqffnmpgqmxqatvamwaqvogmdottva__yhjbuvco_wytdxssnbqrlqlvcaltxwfaej_ycvlcdqzwxphhwxitcvrpzcdrmmfancifskzzpltgpyskiqpcqiwsufibt_pvquhqadcllygxcshnbrudltm_pkjyfnolo_wqdwhbwpuvduuodtkfhqqzmvjfhvsfdhyi_fkhuspwvqiaestpgkqelgo_lnmmodlmfmyggpizxbjautpleio_zalvo_ryrymndvnzqyermzsrycngihghtampsdpidttqdmqo_iwieomfruotxfduawlrxsbuoncjmqehmtiyqzbilxloywkmtrbvmg__fxczgkcxecgjobcfenwztzivnfwijcmjlqcqcxdkozmjbmfxxuwlawcinh_lbzmepageirjmszxlwfqiaeisrfnuxpiexsgpjo_hvaojqyzqrkdohewbeipbvbqmefftjixqrnzrufbc_ombxljpmiedfnra_ugpnispsrrsuoeckawzsdfvwlgmwxub_hpccvlbwyyyqcxdcsl_f_vwvsgzptetyyjuemsnpkpcgdlxkuyyljhcquwrivsvuhbwvhf_jtgnvvlqpgufpvlgbtlhfrzxfhxoeolhq_muflllumega");
    map<char, int> count = countChar(input);
    map<int, char> sorted =  sortByCount(count);
    string output = crop(sorted, '_');

    cout << output << endl;

    return 0;
}