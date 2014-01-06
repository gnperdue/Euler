if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <S-Tab> <Plug>snipMateBack
inoremap <silent> <Plug>snipMateShow =snipMate#ShowAvailableSnips()
inoremap <silent> <Plug>snipMateBack =snipMate#BackwardsSnippet()
inoremap <silent> <Plug>snipMateTrigger =snipMate#TriggerSnippet(1)
inoremap <silent> <Plug>snipMateNextOrTrigger =snipMate#TriggerSnippet()
inoremap <F2> :wi
xmap 	 <Plug>snipMateVisual
smap 	 <Plug>snipMateNextOrTrigger
vnoremap   zf
nnoremap <silent>   @=(foldlevel('.')?'za':'l')
nnoremap -w :execute "normal! gg" . '/\v\s+$' . "\<cr>"
nnoremap -c :noh
nnoremap -? ?\v
nnoremap -/ /\v
nnoremap -pb :execute "rightbelow vsplit " . bufname("#")
vnoremap -" a"`<i"`>f"
nnoremap -" viwa"hbi"lel
nnoremap -sv :source $MYVIMRC
nnoremap -ev :vsplit $MYVIMRC
nmap \\u <Plug>CommentaryUndo
nmap \\\ <Plug>CommentaryLine
nmap \\ <Plug>Commentary
xmap \\ <Plug>Commentary
nmap gx <Plug>NetrwBrowseX
nmap gcu <Plug>CommentaryUndo
nmap gcc <Plug>CommentaryLine
nmap gc <Plug>Commentary
xmap gc <Plug>Commentary
onoremap <silent> io :normal vio
vmap <silent> io <Plug>InnerOffside
snoremap <BS> b<BS>
smap <S-Tab> <Plug>snipMateBack
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
snoremap <silent> <Plug>snipMateBack a=snipMate#BackwardsSnippet()
snoremap <silent> <Plug>snipMateNextOrTrigger a=snipMate#TriggerSnippet()
nnoremap <F5> :!ctags -R --exclude=.git
noremap <F4> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,
nnoremap <F2> :w
nnoremap <Right> :bn
nnoremap <Left> :bp
nnoremap <Down> ddp
nnoremap <Up> ddkP
inoremap  ddi
imap 	 <Plug>snipMateNextOrTrigger
imap 	 <Plug>snipMateShow
inoremap  viwUea
let &cpo=s:cpo_save
unlet s:cpo_save
set autowrite
set background=dark
set backspace=indent,eol,start
set backup
set backupdir=~/.vim_backup/2014.01.06
set backupext=.10.23.42
set cmdheight=2
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set listchars=eol:$,tab:>-,trail:~,extends:>,precedes:<
set modelines=0
set nrformats=
set operatorfunc=<SNR>35_go
set pastetoggle=<F6>
set ruler
set runtimepath=~/.vim,~/.vim/bundle/haskellmode-vim,~/.vim/bundle/html-template-syntax,~/.vim/bundle/jshint,~/.vim/bundle/neco-ghc,~/.vim/bundle/syntastic,~/.vim/bundle/tabular,~/.vim/bundle/tlib_vim,~/.vim/bundle/vim-addon-mw-utils,~/.vim/bundle/vim-asciidoc-sr,~/.vim/bundle/vim-commentary,~/.vim/bundle/vim-javascript-syntax,~/.vim/bundle/vim-json,~/.vim/bundle/vim-markdown,~/.vim/bundle/vim-snipmate,~/.vim/bundle/vim-snippets,~/.vim/bundle/vim2hs,~/.vim/bundle/vimerl,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,~/.vim/bundle/html-template-syntax/after,~/.vim/bundle/tabular/after,~/.vim/bundle/vim-snipmate/after,~/.vim/bundle/vim2hs/after,~/.vim/after
set shiftwidth=2
set showmatch
set smartcase
set statusline=%f\ -\ %c\ -\ %l/%L\ -\ %n\ -\ %y
set tabstop=2
set viminfo='10,\"100,:20,%,n~/.viminfo
set window=0
" vim: set ft=vim :
