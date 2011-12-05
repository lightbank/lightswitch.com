<?php // This file is protected by copyright law and provided under license. Reverse engineering of this file is strictly prohibited.




































































































$Szxck46265869MeucQ=153130432;$hhvdS80378418JOYDZ=249835388;$JJSpM86893311rrTWE=492878235;$lTJet91123047UDBfO=913477723;$wyDcw73380127RVicX=44352600;$irkal58977051RVrOz=913721619;$VHUaW28226318HZtdG=56303527;$dBimv96440430Dgioh=500317078;$LVnhF63931885ZoIQm=778481018;$MmJKw46013183UrmtT=922014100;$TXUze22996826pwrlj=462635071;$xChgj20195312kRdIT=430562683;$SAsBW17921142CKUPf=357515686;$FmNvd41486816XwXyW=274712829;$LySjQ71204834dQWpC=712872864;$bnycW42387695ALbKU=704214539;$bZcmj25347900IIeNs=779456604;$TtCmt45397949zAhKo=969817811;$fcgVB82850342oabhF=807016907;$nYOXg73017578LLEzx=322272644;$WNLAC86212159uXBsT=46303772;$agTZd57746582tQTVE=10329040;$aDVmz57933350JWSvC=745067200;$naVLm22084961HWUUZ=283736999;$rpktR20513916fQsFe=156057190;$rrNUw78532715qqXKU=393246521;$XdDZH86453858wrLLj=527023743;$vPVZp69589844elInr=588607605;$tnNip98253174lbpaJ=109716858;$GbrLl17756347iaouv=120570251;$XXCyy78411865eVweF=152886535;$aYIzs35532226EKOCM=237884460;$RACeH49429932DJmqO=906282776;$vcXiS55417480QWxyN=191300232;$aTklv33807373GiDmR=621655579;$hurjB99912110grIBU=230567566;$QstFd54044189ozhHG=547754944;$rMvCV11516113tRYLl=605436463;$faHyK42640381kLteE=934330872;$ujkve82729492lgTTN=566656921;$VCmxS22095947kaQYu=33133361;$OiLwQ66052246XbFZo=363978943;$LjQZN14910888xTDPH=91912414;$BBtNY73984375zdmFe=247152527;$STySs43585205MOkWL=361418030;$jXPmR39025879CoVIA=465927673;$Rlmml40618896gSqcp=92400207;$HhPAI73676758JkzUS=271054382;$psVyF28511963mscRn=533608948;$Gjzfr20437011iKeqh=911282654;?><?php class SiteCrawler { function ffpknLH3lruh(&$a, $sTOHkwY0EiWi, $T_IVB6tYAThxWS, $PqrWr4MLtujWK1b_W, $mWaGjhtsk5qfq6cQTZJ) { global $grab_parameters; $a = str_replace(':80/', '/', $a); if($a[0]=='?')$a = preg_replace('#^([^\?]*?)([^/\?]*?)(\?.*)?$#','$2',$sTOHkwY0EiWi).$a; if(preg_match('#^https?(:|&\#58;)#is',$a)); else if($a&&$a[0]=='/')$a = $T_IVB6tYAThxWS.$a; else $a = $PqrWr4MLtujWK1b_W.$a; $a=str_replace('/./','/',$a); if(substr($a,-2) == '..')$a.='/';if(strstr($a,'../')){ preg_match('#(.*?:.*?//.*?)(/.*)$#',$a,$aa); 
																											 do{ $ap = $aa[2]; $aa[2] = preg_replace('#/?[^/]*/\.\.#','',$ap,1); }while($aa[2]!=$ap); $a = $aa[1].$aa[2]; } $a = preg_replace('#/\./#','/',$a); $a = str_replace('&#38;','&',$a); $a = str_replace('&amp;','&',$a); $a = preg_replace('#\#.*$#','',$a); $a = preg_replace('#^([^\?]*[^/\:]/)/+#','\\1',$a); $a = preg_replace('#[\r\n]+#s','',$a); $Ng9XfYD8bn = (strtolower(substr($a,0,strlen($mWaGjhtsk5qfq6cQTZJ)) ) != strtolower($mWaGjhtsk5qfq6cQTZJ)); if($_GET['ddbg2'])echo "($a)<br>\n";//exit; 
																											 return $Ng9XfYD8bn; } function ZoknvuUYP($iXkV1DXrsnU,&$urls_completed) { global $grab_parameters,$Nt_1IROZP14owm4DAeH; error_reporting(E_ALL&~E_NOTICE); @set_time_limit($grab_parameters['xs_exec_time']); if($iXkV1DXrsnU['bgexec']) { ignore_user_abort(true); } register_shutdown_function('t7RRTKqTzMKk'); if(function_exists('ini_set')) { @ini_set("zlib.output_compression", 0); @ini_set("output_buffering", 0); } $Niq61B3f5T = explode(" ",microtime()); $uW2s6L508AR = $Niq61B3f5T[0]+$Niq61B3f5T[1]; $awjs5cXHLQKLCojjfKj = $iXkV1DXrsnU['initurl']; $F1JJx6h86dbaJkcg = $iXkV1DXrsnU['maxpg']>0 ? $iXkV1DXrsnU['maxpg'] : 1E10; $OBfrooBYrp0IcNgFcy5 = $iXkV1DXrsnU['maxdepth'] ? $iXkV1DXrsnU['maxdepth'] : -1; $XQa0UewN3f = $iXkV1DXrsnU['progress_callback']; $lyojZa6FTE2_d0 = preg_replace("#\s*[\r\n]+\s*#",'|', (strstr($s=trim($grab_parameters['xs_excl_urls']),'*')?$s:preg_quote($s,'#'))); $GYOAxf_ifFR12047x4j = preg_replace("#\s*[\r\n]+\s*#",'|', (strstr($s=trim($grab_parameters['xs_incl_urls']),'*')?$s:preg_quote($s,'#'))); $hSaCvxHsKMVb0F = $ZTcqdz3WBLUhzHN0w = array(); $qHEfslblz = preg_split('#[\r\n]+#', $grab_parameters['xs_ind_attr']); $QNBZB8U2gUbUbMO = '#200'.($grab_parameters['xs_allow_httpcode']?'|'.$grab_parameters['xs_allow_httpcode']:'').'#'; if($grab_parameters['xs_memsave']) { if(!file_exists(Znq7ffD8tRtK7G7k)) mkdir(Znq7ffD8tRtK7G7k, 0777); else if($iXkV1DXrsnU['resume']=='') HZpRje35mVkO0jMR(Znq7ffD8tRtK7G7k, '.txt'); } foreach($qHEfslblz as $ia) if($ia) { $is = explode(',', $ia); if($is[0][0]=='$') $vPMSF5pieFsrixtq8t = substr($is[0], 1); else $vPMSF5pieFsrixtq8t = str_replace('\\$','$',preg_quote($is[0],'#')); $ZTcqdz3WBLUhzHN0w[] = $vPMSF5pieFsrixtq8t; $hSaCvxHsKMVb0F[str_replace('$','',$is[0])]=array('lm'=>$is[1], 'f'=>$is[2], 'p'=>$is[3]); } if($ZTcqdz3WBLUhzHN0w) $LzzEy5A_btN = implode('|',$ZTcqdz3WBLUhzHN0w); $HBsKYMirP = parse_url($awjs5cXHLQKLCojjfKj); if(!$HBsKYMirP['path']){$awjs5cXHLQKLCojjfKj.='/';$HBsKYMirP = parse_url($awjs5cXHLQKLCojjfKj);} $qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch($awjs5cXHLQKLCojjfKj,0,true);// the first request is to skip session id 
																											 $qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch($awjs5cXHLQKLCojjfKj,0,true); $hPqMY1ez6oMQQl = !preg_match($QNBZB8U2gUbUbMO,$qFRPmUDRi['code']); if($hPqMY1ez6oMQQl) { $hPqMY1ez6oMQQl = ''; foreach($qFRPmUDRi['headers'] as $k=>$v) $hPqMY1ez6oMQQl .= $k.': '.$v.'<br />'; return array( 'errmsg'=>'<b>There was an error while retrieving the URL specified:</b> '.$awjs5cXHLQKLCojjfKj.''. ($qFRPmUDRi['errormsg']?'<br><b>Error message:</b> '.$qFRPmUDRi['errormsg']:''). '<br><b>HTTP headers follow:</b><br>'.$hPqMY1ez6oMQQl. '<br><b>HTTP output:</b><br>'.$qFRPmUDRi['content'] , ); } $awjs5cXHLQKLCojjfKj = $qFRPmUDRi['last_url']; $urls_completed = array(); $urls_ext = array(); $urls_404 = array(); $T_IVB6tYAThxWS = $HBsKYMirP['scheme'].'://'.$HBsKYMirP['host'].((!$HBsKYMirP['port'] || ($HBsKYMirP['port']=='80'))?'':(':'.$HBsKYMirP['port'])); 
																											 $pn = $tsize = 0; $mWaGjhtsk5qfq6cQTZJ = preg_replace('#([^/\:]/)/+#','\\1',$T_IVB6tYAThxWS.'/'.DoodEx665K($HBsKYMirP['path'])); $mO8dP_vKE = preg_replace('#^.+://[^/]+#', '', $mWaGjhtsk5qfq6cQTZJ); 
																											 $GZCFp_txIxdI = $Nt_1IROZP14owm4DAeH->fetch($awjs5cXHLQKLCojjfKj,0,true,true); $Tsr1dxbRSl36XZQSmy2 = str_replace($mWaGjhtsk5qfq6cQTZJ,'',$awjs5cXHLQKLCojjfKj); $urls_list_full = array($Tsr1dxbRSl36XZQSmy2); if(!$Tsr1dxbRSl36XZQSmy2)$Tsr1dxbRSl36XZQSmy2='/'; $urls_list = array($Tsr1dxbRSl36XZQSmy2); $urls_list2 = array(); $ZdD16fdro7T29 = array(); $links_level = 0; $tqAifGeogXJRviudvJ1 = $ref_links = $ref_links2 = array(); $Pg9z9L_vlxcCxaz = 0; $O3mTecPWsZVPj45u = $F1JJx6h86dbaJkcg; if(!$grab_parameters['xs_progupdate'])$grab_parameters['xs_progupdate'] = 20; if(isset($grab_parameters['xs_robotstxt']) && $grab_parameters['xs_robotstxt']) { $qNh0L3Iqq4xOGQ = $Nt_1IROZP14owm4DAeH->fetch($T_IVB6tYAThxWS.'/robots.txt'); if($T_IVB6tYAThxWS.'/' != $mWaGjhtsk5qfq6cQTZJ) { $WKLxFNU9Afmx3X = "\n".$Nt_1IROZP14owm4DAeH->fetch($mWaGjhtsk5qfq6cQTZJ.'robots.txt'); $qNh0L3Iqq4xOGQ['content']  .= "\n".$WKLxFNU9Afmx3X['content']; } $ra=preg_split('#user-agent:\s*#im',$qNh0L3Iqq4xOGQ['content']); $gCmDgG11zRQ1aO=array(); for($i=1;$i<count($ra);$i++){ preg_match('#^(\S+)(.*)$#s',$ra[$i],$X586Srhrb7zbBwwaEu); if($X586Srhrb7zbBwwaEu[1]=='*'||strstr($X586Srhrb7zbBwwaEu[1],'google')){ preg_match_all('#^disallow:[^\r\n\S](\S*)#im',$X586Srhrb7zbBwwaEu[2],$rm); for($pi=0;$pi<count($rm[1]);$pi++) if($rm[1][$pi]) $gCmDgG11zRQ1aO[] =  str_replace('\\$','$', str_replace('\\*','.*', preg_quote($rm[1][$pi],'#') )); } } for($i=0;$i<count($gCmDgG11zRQ1aO);$i+=200) $Z0CT90Qqb49cBckp1[]=implode('|', array_slice($gCmDgG11zRQ1aO, $i,200)); }else $Z0CT90Qqb49cBckp1 = array(); $Ink66j0Yx4uzSWU5 = $grab_parameters['xs_exc_skip']!='\\.()'; $spA7fV5_CrBgFVbOJ = $grab_parameters['xs_inc_skip']!='\\.()'; $grab_parameters['xs_inc_skip'] .= '$'; $grab_parameters['xs_exc_skip'] .= '$'; if($grab_parameters['xs_debug']) $_GET['ddbg']=1; $i64_RzaxP7PMd7s = 0; $url_ind = 0; $cnu = 1; $pf = fopen(sMuf2pf0iKaQ.jgYSLBDPtmpAo,'w');fclose($pf); if($iXkV1DXrsnU['resume']!=''){ $T0gmFEXXIurPo = @ZBWGkqS6VQ71(GHJEfA2QYqwa(sMuf2pf0iKaQ.KH6aKAnNWiCYJWvf)); echo 'Resuming the last session (last updated: '.date('Y-m-d H:i:s',$T0gmFEXXIurPo['time']).')'."\n"; if($T0gmFEXXIurPo) extract($T0gmFEXXIurPo); $uW2s6L508AR-=$ctime; $i64_RzaxP7PMd7s = $ctime; unset($T0gmFEXXIurPo); } sleep(1); @unlink(sMuf2pf0iKaQ.jgYSLBDPtmpAo); if($urls_list) do { $sTOHkwY0EiWi = $urls_list[$url_ind++]; unset($urls_list[$url_ind-1]);   $HDxSUg0eWtUQjt = DXwTWcPx8gwRJFL($sTOHkwY0EiWi); $qFRPmUDRi = array(); $cn = ''; if(isset($ZdD16fdro7T29[$sTOHkwY0EiWi])) $sTOHkwY0EiWi=$ZdD16fdro7T29[$sTOHkwY0EiWi]; $f = $Ink66j0Yx4uzSWU5 && preg_match('#'.$grab_parameters['xs_exc_skip'].'#i',$sTOHkwY0EiWi); if($lyojZa6FTE2_d0&&!$f)$f=$f||preg_match('#('.$lyojZa6FTE2_d0.')#',$sTOHkwY0EiWi); if($Z0CT90Qqb49cBckp1&&!$f) foreach($Z0CT90Qqb49cBckp1 as $bm) { $f = $f||preg_match('#^('.$bm.')#',$mO8dP_vKE.$sTOHkwY0EiWi); } $f2 = false; if(!$f) { $f2 = $spA7fV5_CrBgFVbOJ && preg_match('#'.$grab_parameters['xs_inc_skip'].'#i',$sTOHkwY0EiWi); if($GYOAxf_ifFR12047x4j&&!$f2) $f2 = $f2||(preg_match('#('.$GYOAxf_ifFR12047x4j.')#',$sTOHkwY0EiWi)); if($grab_parameters['xs_parse_only'] && !$f2 && $sTOHkwY0EiWi!='/') { $f2 = $f2 || !preg_match('#'.str_replace(' ', '|', preg_quote($grab_parameters['xs_parse_only'],'#')).'#',$sTOHkwY0EiWi); } } do{ if(!$f && !$f2)// && ($O3mTecPWsZVPj45u*1.2>(count($urls_list)+count($urls_completed)-$url_ind))) 
																											 { if($OBfrooBYrp0IcNgFcy5<=0 || $links_level<$OBfrooBYrp0IcNgFcy5) { $plZxxPxp7dp = preg_replace('#([^/\:]/)/+#','\\1',$mWaGjhtsk5qfq6cQTZJ.$sTOHkwY0EiWi); if($_GET['ddbg'])echo "<h4> { $plZxxPxp7dp } </h4>";flush(); $UVtSAwQYOsEzzCeKfY=0; do { $qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch($plZxxPxp7dp, 0, 1); if($qFRPmUDRi['code']==403) { $UVtSAwQYOsEzzCeKfY++; sleep($grab_parameters['xs_delay_ms']?$grab_parameters['xs_delay_ms']:1); } else $UVtSAwQYOsEzzCeKfY=5; }while($UVtSAwQYOsEzzCeKfY<3); if($_GET['ddbg']){echo "<hr> [[[ ".$qFRPmUDRi['code']." ]]] ";print_r($qFRPmUDRi['headers']);flush();} $JcYkhlEMDOd63veSaCB = is_array($qFRPmUDRi['headers']) ? strtolower($qFRPmUDRi['headers']['content-type']) : ''; if(!strstr($JcYkhlEMDOd63veSaCB,'text/html')&&!strstr($JcYkhlEMDOd63veSaCB,'/xhtml') && (!$grab_parameters['xs_parse_swf'] || !strstr($JcYkhlEMDOd63veSaCB, 'shockwave-flash')) ) continue; $sfWFJIHHoHQFy = array(); if($qFRPmUDRi['code']==404){ $urls_404[]=array($sTOHkwY0EiWi,$ref_links2[$sTOHkwY0EiWi]); } if($QNBZB8U2gUbUbMO && !preg_match($QNBZB8U2gUbUbMO,$qFRPmUDRi['code'])) continue; $cn = $qFRPmUDRi['content']; $tsize+=strlen($cn); if($LKwlfmXlFQZwAHyN = preg_replace('#<!--(\[if IE\]>|.*?-->)#is', '',$cn)) $cn = $LKwlfmXlFQZwAHyN; if($grab_parameters['xs_canonical']) if(($plZxxPxp7dp == $qFRPmUDRi['last_url']) && preg_match('#<link[^>]*rel="canonical"[^>]href="([^>]*?)"#', $cn, $NETkCwdzdq6Pz0ny)) $qFRPmUDRi['last_url'] = $NETkCwdzdq6Pz0ny[1]; $sxtMVK6zQKt = preg_replace('#^.*?'.preg_quote($mWaGjhtsk5qfq6cQTZJ,'#').'#','',$qFRPmUDRi['last_url']); if(($plZxxPxp7dp != $qFRPmUDRi['last_url']) && ($plZxxPxp7dp != $qFRPmUDRi['last_url'].'/')) { $ZdD16fdro7T29[$sTOHkwY0EiWi]=$qFRPmUDRi['last_url']; $io=$sTOHkwY0EiWi; $urls_list2[] = $sxtMVK6zQKt; if(count($ref_links[$sxtMVK6zQKt])<max(1,intval($grab_parameters['xs_maxref']))) $ref_links[$sxtMVK6zQKt][] = $sTOHkwY0EiWi; continue; } preg_match('#<base[^>]*?href=[\'"](.*?)[\'"]#is',$cn,$bm); if(isset($bm[1])&&$bm[1]) $PqrWr4MLtujWK1b_W = DoodEx665K($bm[1].(preg_match('#//.*/#',$bm[1])?'-':'/-')); 
																											 else $PqrWr4MLtujWK1b_W = DoodEx665K($mWaGjhtsk5qfq6cQTZJ.$sTOHkwY0EiWi); if(strstr($JcYkhlEMDOd63veSaCB, 'shockwave-flash')) { include_once sEHr9E0d1xL1nk.'class.pfile.inc.php'; $am = new SWFParser(); $am->Gg5AAIeuiYp($cn); $oL4Wd5vimhWp8DF0q = $am->KC5A4W9FxdMzpD0q(); }else { $Svxm9M4Rsbj0b = $grab_parameters['xs_utf8_enc'] ? 'isu':'is'; preg_match_all('#<(?:a|area|go)\s[^>]*?href\s*=\s*(?:"([^"]*)|\'([^\']*)|([^\s\">]+)).*?>#'.$Svxm9M4Rsbj0b, $cn, $am);
																											
																											preg_match_all('#<i?frame\s[^>]*src\s*=\s*["\']?(.*?)("|>|\'[>\s])#'.$Svxm9M4Rsbj0b, $cn, $Dyz4i63tIZpcSycZz04);
																											
																											preg_match_all('#<meta\s[^>]*http-equiv\s*=\s*"?refresh[^>]*URL\s*=\s*["\']?(.*?)("|>|\'[>\s])#'.$Svxm9M4Rsbj0b, $cn, $pP9L3mrPigC);
																											
																											if($grab_parameters['xs_parse_swf'])
																											
																											preg_match_all('#<object[^>]*application/x-shockwave-flash[^>]*data\s*=\s*["\']([^"\'>]+).*?>#'.$Svxm9M4Rsbj0b, $cn, $oL4Wd5vimhWp8DF0q);
																											
																											else $oL4Wd5vimhWp8DF0q = array(array(),array());
																											
																											
																											$sfWFJIHHoHQFy = array();
																											
																											for($i=0;$i<count($am[1]);$i++)
																											
																											{
																											
																											if( !preg_match('#rel=["\']nofollow#i', $am[0][$i]) ) 
																											
																											$sfWFJIHHoHQFy[] = $am[1][$i];
																											
																											}
																											
																											$sfWFJIHHoHQFy = @array_merge(
																											
																											$sfWFJIHHoHQFy,
																											
																											
																											$am[2],$am[3],  
																											
																											$Dyz4i63tIZpcSycZz04[1],$pP9L3mrPigC[1],
																											
																											$oL4Wd5vimhWp8DF0q[1]);
																											
																											}
																											
																											$sfWFJIHHoHQFy = array_unique($sfWFJIHHoHQFy);
																											
																											
																											
																											$nn = $nt = 0;
																											
																											reset($sfWFJIHHoHQFy);
																											
																											if(preg_match('#<meta name="robots" content="[^"]*?nofollow#is',$cn))
																											
																											$sfWFJIHHoHQFy = array();
																											
																											foreach($sfWFJIHHoHQFy as $i=>$ll)
																											
																											if($ll)
																											
																											{                    
																											
																											$a = $sa = trim($ll);
																											
																											
																											if($grab_parameters['xs_proto_skip'] && 
																											
																											(preg_match('#^'.$grab_parameters['xs_proto_skip'].'#i',$a)||
																											
																											($Ink66j0Yx4uzSWU5 && preg_match('#'.$grab_parameters['xs_exc_skip'].'#i',$a))||
																											
																											preg_match('#^'.$grab_parameters['xs_proto_skip'].'#i',function_exists('html_entity_decode')?html_entity_decode($a):$a)
																											
																											))
																											
																											continue;
																											
																											if($grab_parameters['xs_exclude_check'])
																											
																											{
																											
																											$_f=$_f2=false;
																											
																											$_f=$lyojZa6FTE2_d0&&preg_match('#('.$lyojZa6FTE2_d0.')#',$a);
																											
																											if($Z0CT90Qqb49cBckp1&&!$_f)
																											
																											foreach($Z0CT90Qqb49cBckp1 as $bm)
																											
																											$_f = $_f||preg_match('#^('.$bm.')#',$mO8dP_vKE.$sTOHkwY0EiWi);
																											
																											if($_f)continue;
																											
																											}
																											
																											$Ng9XfYD8bn = $this->ffpknLH3lruh($a, $sTOHkwY0EiWi, $T_IVB6tYAThxWS, $PqrWr4MLtujWK1b_W, $mWaGjhtsk5qfq6cQTZJ);
																											
																											$sxtMVK6zQKt = substr($a,strlen($mWaGjhtsk5qfq6cQTZJ));
																											
																											$sxtMVK6zQKt = str_replace(' ', '%20', $sxtMVK6zQKt);
																											
																											if($grab_parameters['xs_cleanurls'])
																											
																											$sxtMVK6zQKt = @preg_replace($grab_parameters['xs_cleanurls'],'',$sxtMVK6zQKt);
																											
																											if($grab_parameters['xs_cleanpar'])
																											
																											{
																											
																											$sxtMVK6zQKt = @preg_replace('#[\\?\\&]('.$grab_parameters['xs_cleanpar'].')=[a-z0-9\-\_]+$#i','',$sxtMVK6zQKt);
																											
																											$sxtMVK6zQKt = @preg_replace('#([\\?\\&])('.$grab_parameters['xs_cleanpar'].')=[a-z0-9\-\_]+&#i','$1',$sxtMVK6zQKt);
																											
																											}
																											
																											if($Ng9XfYD8bn)
																											
																											{
																											
																											if($grab_parameters['xs_extlinks'] && !$urls_ext[$a])
																											
																											$urls_ext[$a] = $plZxxPxp7dp;
																											
																											continue;
																											
																											}
																											
																											if($_GET['ddbg3'])echo "<u>[$a]</u><br>\n";//exit;
																											
																											$urls_list2[] = $sxtMVK6zQKt;
																											
																											if($grab_parameters['xs_maxref'] && count($ref_links[$sxtMVK6zQKt])<$grab_parameters['xs_maxref'])
																											
																											$ref_links[$sxtMVK6zQKt][] = $sTOHkwY0EiWi;
																											
																											$nt++;
																											
																											}
																											
																											unset($sfWFJIHHoHQFy);
																											
																											}
																											
																											}                                        
																											
																											
																											
																											if($grab_parameters['xs_incl_only'] && !$f)
																											
																											$f = $f || !preg_match('#'.str_replace(' ', '|', preg_quote($grab_parameters['xs_incl_only'],'#')).'#',$mWaGjhtsk5qfq6cQTZJ.$sTOHkwY0EiWi);
																											
																											if(!$f) $f = $f||preg_match('#<meta name="robots" content="[^"]*?noindex#is',$cn);
																											
																											if(!$f)
																											
																											{
																											
																											$ZNulaCcO5edar0rP = array(
																											
																											
																											'link'=>preg_replace('#//+$#','/', preg_replace('#^([^/\:\?]/)/+#','\\1',$mWaGjhtsk5qfq6cQTZJ.$sTOHkwY0EiWi))
																											
																											);
																											
																											if($grab_parameters['xs_makehtml'])
																											
																											{
																											
																											preg_match('#<title>(.*?)</title>#is', $qFRPmUDRi['content'], $WyXkTyAK3kSMA);
																											
																											$ZNulaCcO5edar0rP['t'] = strip_tags($WyXkTyAK3kSMA[1]);
																											
																											}
																											
																											if($grab_parameters['xs_metadesc'])
																											
																											{
																											
																											preg_match('#<meta\s[^>]*(?:http-equiv|name)\s*=\s*"?description[^>]*content\s*=\s*["]?([^>\"]*)#is', $cn, $Dm3PRno_nAd);
																											
																											if($Dm3PRno_nAd[1])
																											
																											$ZNulaCcO5edar0rP['d'] = $Dm3PRno_nAd[1];
																											
																											}
																											
																											if($grab_parameters['xs_makeror']||$grab_parameters['xs_autopriority'])
																											
																											$ZNulaCcO5edar0rP['o'] = max(0,$links_level);
																											
																											if(preg_match('#('.$LzzEy5A_btN.')#',$mWaGjhtsk5qfq6cQTZJ.$sTOHkwY0EiWi,$IVvqfIlb3rHfBU9))
																											
																											{
																											
																											$ZNulaCcO5edar0rP['clm'] = $hSaCvxHsKMVb0F[$IVvqfIlb3rHfBU9[1]]['lm'];
																											
																											$ZNulaCcO5edar0rP['f'] = $hSaCvxHsKMVb0F[$IVvqfIlb3rHfBU9[1]]['f'];
																											
																											$ZNulaCcO5edar0rP['p'] = $hSaCvxHsKMVb0F[$IVvqfIlb3rHfBU9[1]]['p'];
																											
																											}
																											
																											$xz = 'img';
																											
																											if($grab_parameters['xs_imginfo'])
																											
																											{
																											
																											preg_match_all('#<img[^>]*src=[\'"](.*?)[\'"].*?>#is', $cn, $yiI3GJqLr5Z, PREG_SET_ORDER);
																											
																											$ai = $ae = array();
																											
																											foreach($yiI3GJqLr5Z as $im)
																											
																											{
																											
																											$Ng9XfYD8bn = $this->ffpknLH3lruh($im[1], $sTOHkwY0EiWi, $T_IVB6tYAThxWS, $PqrWr4MLtujWK1b_W, $mWaGjhtsk5qfq6cQTZJ);
																											
																											if($Ng9XfYD8bn) 
																											
																											continue;
																											
																											if($grab_parameters['xs_imgincmask'])
																											
																											if(!preg_match('#'.str_replace(' ', '|', preg_quote($grab_parameters['xs_imgincmask'],'#')).'#',$im[0]))
																											
																											continue;
																											
																											if(!$lyojZa6FTE2_d0||!preg_match('#('.$lyojZa6FTE2_d0.')#',$im[1]))
																											
																											{
																											
																											if(!$X73TkgN6YvHVm7YdDF[$im[1]]++)
																											
																											{
																											
																											preg_match('#(?:title|alt)="(.*?)"#i', $im[0], $tm);
																											
																											$t =$tm[1];
																											
																											$ai[] = array($im[1], $t);
																											
																											}
																											
																											}
																											
																											}
																											
																											if($ai)
																											
																											$ZNulaCcO5edar0rP['i'] = $ai;
																											
																											}
																											
																											$xz = '/img';
																											
																											$xz = 'video';
																											
																											if($grab_parameters['xs_videoinfo'])
																											
																											{
																											
																											$ai = array(
																											
																											'http://www.youtube(?:-nocookie)?.com/(?:v/|embed/|watch\?v=)',
																											
																											'http://video.google.com/googleplayer\.swf\?docid=',
																											
																											'http://player.vimeo.com/video/',
																											
																											'http://www.dailymotion.com/swf/video/',
																											
																											'http://(?:media.mtvnservices.com|www.mtv.com/player/)[^>]*?vid(?:=|%3D)',
																											
																											'http://blip.tv/play/',
																											
																											);
																											
																											
																											
																											$ai = '(?:'. implode('|', $ai).')';
																											
																											
																											$ai = '('.$ai.'([a-z0-9\-\_]+))';
																											
																											
																											preg_match_all('#<param[^>]*name=[\'"\s]*?(?:movie|src)[^>]*value=[\'"\s]*?'.$ai.'#is', $cn, $yiI3GJqLr5Z, PREG_SET_ORDER);
																											
																											preg_match_all('#flashvars\s*=\s*\{[^\}]*?file:\s*[\'"]'.$ai.'#is', $cn, $RWenvmRCuyBW, PREG_SET_ORDER);
																											
																											preg_match_all('#<embed[^>]*src=[\'"\s]*?'.$ai.'#is', $cn, $oL4Wd5vimhWp8DF0q, PREG_SET_ORDER);
																											
																											preg_match_all('#<iframe[^>]*src=[^>]*?'.$ai.'#is', $cn, $eiTxuqFQGsvY, PREG_SET_ORDER);
																											
																											preg_match_all('#\.addVariable\([\'\"]file[\'\"],[\'\"]'.$ai.'#is', $cn, $t, PREG_SET_ORDER);
																											
																											$ai = $ae = array();
																											
																											$yiI3GJqLr5Z = array_merge($yiI3GJqLr5Z,$oL4Wd5vimhWp8DF0q,$eiTxuqFQGsvY,$RWenvmRCuyBW, $t);
																											
																											foreach($yiI3GJqLr5Z as $im)
																											
																											{
																											
																											if(!$X73TkgN6YvHVm7YdDF[trim($im[2])]++)
																											
																											$ai[] = array($im[1],$im[2]);
																											
																											}
																											
																											if($ai)
																											
																											$ZNulaCcO5edar0rP['v'] = $ai;
																											
																											if(function_exists('xml_extra_video_step1'))
																											
																											xml_extra_video_step1($ZNulaCcO5edar0rP, $cn, $X73TkgN6YvHVm7YdDF);
																											
																											}
																											
																											$xz = '/video';
																											
																											if($grab_parameters['xs_lastmod_notparsed'] && $f2)
																											
																											{
																											
																											$qFRPmUDRi = $Nt_1IROZP14owm4DAeH->fetch($plZxxPxp7dp, 0, 1, false, "", array('req'=>'HEAD'));
																											
																											
																											}
																											
																											if(!$ZNulaCcO5edar0rP['lm'] && isset($qFRPmUDRi['headers']['last-modified']))
																											
																											$ZNulaCcO5edar0rP['lm']=$qFRPmUDRi['headers']['last-modified'];
																											
																											if($_GET['ddbg'])echo "((include ".$ZNulaCcO5edar0rP['link']."))<br />";flush();
																											
																											if($grab_parameters['xs_memsave'])
																											
																											{
																											
																											ZSdWi6bIZ81cvoz2uwc($HDxSUg0eWtUQjt, $ZNulaCcO5edar0rP);
																											
																											$urls_completed[] = $HDxSUg0eWtUQjt;
																											
																											}else
																											
																											$urls_completed[] = $ZNulaCcO5edar0rP;
																											
																											$O3mTecPWsZVPj45u = $F1JJx6h86dbaJkcg - count($urls_completed);
																											
																											}
																											
																											}while(false);// zerowhile
																											
																											if($url_ind>=$cnu)
																											
																											{
																											
																											unset($urls_list);
																											
																											$url_ind = 0;
																											
																											$urls_list = array_values(array_unique(array_diff($urls_list2,$urls_list_full)));
																											
																											$urls_list_full = array_merge($urls_list_full,$urls_list);
																											
																											$cnu = count($urls_list);
																											
																											unset($ref_links2);
																											
																											$ref_links2 = $ref_links;
																											
																											unset($ref_links); unset($urls_list2);
																											
																											$ref_links = array();
																											
																											$urls_list2 = array();
																											
																											$links_level++;
																											
																											}
																											
																											$pn++;
																											
																											$Niq61B3f5T=explode(" ",microtime());
																											
																											$ctime = $Niq61B3f5T[0]+$Niq61B3f5T[1] - $uW2s6L508AR;
																											
																											$pl=min($cnu-$url_ind,$O3mTecPWsZVPj45u);
																											
																											if( ($cnu==$url_ind || $pl==0||$pn==1 || ($pn%$grab_parameters['xs_progupdate'])==0)
																											
																											|| count($urls_completed)>=$F1JJx6h86dbaJkcg)
																											
																											{
																											
																											if(strstr($GZCFp_txIxdI['content'],'header'))break;
																											
																											$mu = function_exists('memory_get_usage') ? memory_get_usage() : '-';
																											
																											if(intval($mu))
																											
																											$mu = number_format($mu/1024,1).' Kb';
																											
																											if($_GET['ddbg'])echo "(memory: $mu)<br>\n";//exit;
																											
																											$urls_list2 = array_values(array_unique($urls_list2));
																											
																											$JXrAUXdkHB6bEow = array(
																											
																											$ctime, // running time
																											
																											str_replace($awjs5cXHLQKLCojjfKj, '', $sTOHkwY0EiWi),  // current URL
																											
																											$pl,                    // urls left
																											
																											$pn,                    // processed urls
																											
																											$tsize,                 // bandwidth usage
																											
																											$links_level,           // depth level
																											
																											$mu,                    // memory usage
																											
																											count($urls_completed), // added in sitemap
																											
																											count($urls_list2)      // in the queue
																											
																											);
																											
																											if($iXkV1DXrsnU['bgexec'])
																											
																											dxY5KOhQceAuFRoi(e6p6oz8D73L8,hVgV5J75NEESyCQgUY($JXrAUXdkHB6bEow));
																											
																											if($XQa0UewN3f && !$f)
																											
																											$XQa0UewN3f($JXrAUXdkHB6bEow);
																											
																											
																											}else
																											
																											{
																											
																											$XQa0UewN3f(array('cmd'=>'ping', 'bg' => $iXkV1DXrsnU['bgexec']));
																											
																											}
																											
																											if($grab_parameters['xs_savestate_time']>0 &&
																											
																											( 
																											
																											($ctime-$i64_RzaxP7PMd7s>$grab_parameters['xs_savestate_time'])
																											
																											|| ($url_ind>=$cnu)
																											
																											)
																											
																											)
																											
																											{
																											
																											$i64_RzaxP7PMd7s = $ctime;
																											
																											if($_GET['ddbg'])echo "(saving dump)<br />\n";flush();
																											
																											$T0gmFEXXIurPo = compact('url_ind',
																											
																											'urls_list','urls_list2','cnu',
																											
																											'ref_links','ref_links2',
																											
																											'urls_list_full','urls_completed',
																											
																											'urls_404',
																											
																											'nt','tsize','pn','links_level','ctime', 'urls_ext'
																											
																											);
																											
																											$T0gmFEXXIurPo['time']=time();
																											
																											$X5pGy9XVxZmKajMLt=hVgV5J75NEESyCQgUY($T0gmFEXXIurPo);
																											
																											dxY5KOhQceAuFRoi(KH6aKAnNWiCYJWvf,$X5pGy9XVxZmKajMLt);
																											
																											unset($T0gmFEXXIurPo);
																											
																											unset($X5pGy9XVxZmKajMLt);
																											
																											}
																											
																											if($grab_parameters['xs_delay_req'] && $grab_parameters['xs_delay_ms'] &&
																											
																											(($pn%$grab_parameters['xs_delay_req'])==0))
																											
																											{
																											
																											sleep($grab_parameters['xs_delay_ms']);
																											
																											}
																											
																											if($inOnsdwxENV3KRYY=file_exists($p0HW1JkR_Vvz=sMuf2pf0iKaQ.jgYSLBDPtmpAo)){
																											
																											if(@unlink($p0HW1JkR_Vvz))
																											
																											break;
																											
																											else
																											
																											$inOnsdwxENV3KRYY=0;
																											
																											}
																											
																											}while(
																											
																											count($urls_completed)<$F1JJx6h86dbaJkcg
																											
																											&&
																											
																											$url_ind<$cnu
																											
																											);
																											
																											if($_GET['ddbgexit'])exit;
																											
																											return array(
																											
																											'u404'=>$urls_404,
																											
																											'ctime'=>$ctime,
																											
																											'tsize'=>$tsize,
																											
																											'errmsg'=>'',
																											
																											'initurl'=>$awjs5cXHLQKLCojjfKj,
																											
																											'initdir'=>$mWaGjhtsk5qfq6cQTZJ,
																											
																											'ucount'=>count($urls_completed),
																											
																											'crcount'=>$pn,
																											
																											'time'=>time(),
																											
																											'params'=>$iXkV1DXrsnU,
																											
																											'interrupt'=>$inOnsdwxENV3KRYY,
																											
																											'urls_ext'=>$urls_ext
																											
																											);
																											
																											}
																											
																											}
																											
																											$nuBa9NbmEO6RBhcW = new SiteCrawler();
																											
																											function t7RRTKqTzMKk(){
																											
																											@unlink(sMuf2pf0iKaQ.e6p6oz8D73L8);
																											
																											}
																											
																											



































































































